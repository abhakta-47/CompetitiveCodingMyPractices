#include <bits/stdc++.h>
#include <numeric>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (ll i = x; i < n; i++)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll get_total_attack(vector<vector<ll>> &attacks, ll cur_turn, ll n) {
    ll total_attack = (ll)0;
    loop(i, 0, n) {
        total_attack +=
            (attacks[i][0] * ((cur_turn - (ll)1) / attacks[i][1] + (ll)1));
    }
    return total_attack;
}

ll count_turns(vector<vector<ll>> &attacks, ll h, ll n) {
    ll start_turn = 1;
    while (h > get_total_attack(attacks, start_turn, n)) {
        start_turn++;
    }
    return start_turn;
}

ll count_turns_recur(vector<vector<ll>> &attacks, ll h, ll n) {
    ll period = attacks[n - 1][2];
    ll period_attack = get_total_attack(attacks, period, n);
    // cout << period_attack << ":" << h << "::";
    cout << h << ":" << n << ":" << period << ":" << period_attack << "\n";

    ll required_period = (h / period_attack) - 1;
    ll cur_turn = required_period * period + 1;

    if (n == 1) {
        cout << "*" << cur_turn << "\n";
        return cur_turn;
    }
    ll ans = cur_turn +
             count_turns_recur(
                 attacks, h - get_total_attack(attacks, cur_turn, n), n - 1);
    cout << "|" << h - get_total_attack(attacks, cur_turn, n) << ":" << n << ":"
         << cur_turn << " :: ";
    cout << ans << "\n";
    return ans;
}

void sol() {
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), c(n);
    loop(i, 0, n) { cin >> a[i]; }
    loop(i, 0, n) { cin >> c[i]; }

    vector<pair<ll, ll>> attacks_temp(n);
    loop(i, 0, n) { attacks_temp[i] = {c[i], a[i]}; }
    sort(attacks_temp.begin(), attacks_temp.end());

    vector<vector<ll>> attacks(n, vector<ll>(3));
    attacks[0][0] = attacks_temp[0].second;
    attacks[0][1] = attacks_temp[0].first;
    attacks[0][2] = attacks_temp[0].first;
    loop(i, 1, n) {
        attacks[i][0] = attacks_temp[i].second;
        attacks[i][1] = attacks_temp[i].first;
        attacks[i][2] = lcm(attacks_temp[i].first, attacks_temp[i - 1].first);
    }

    ll ans = count_turns_recur(attacks, h, n);
    cout << "||" << ans << "\n";

    return;
}

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}