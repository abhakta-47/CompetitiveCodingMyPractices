#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll get_number(string &s, ll pos) {
    ll ans = (s[pos] - '0') * 10 + (s[pos + 1] - '0');
    return ans;
}

ll solve_eq(vector<ll> &eq) {
    ll ans = 0;
    loop(i, 0, eq.size()) {
        if (eq[i] == 0) {
            return 0;
        }
        if (eq[i] == 1) {
            continue;
        }
        ans += eq[i];
    }
    if (ans == 0 && eq.size() > 1)
        return 1;
    // loop(i, 0, eq.size()) { cout << eq[i] << " "; }
    // cout << "=" << ans << "\n";
    return ans;
}

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 2) {
        cout << get_number(s, 0);
        return;
    }
    vector<vector<ll>> pos_eqs;
    loop(curpos, 0, n - 1) {
        vector<ll> eq;
        loop(i, 0, n) {
            if (i == curpos) {
                eq.pb(get_number(s, i));
                ++i;
            } else {
                eq.pb(s[i] - '0');
            }
        }
        pos_eqs.pb(eq);
    }
    // cout << s << ":: ";
    ll ans = solve_eq(pos_eqs[0]);
    loop(i, 1, pos_eqs.size()) { ans = min(ans, solve_eq(pos_eqs[i])); }
    cout << ans;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
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
