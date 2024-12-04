#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (ll i = x; i < n; i++)

ll n, m, k;
vector<pair<ll, ll>> enemies(n);

ll calc(ll pos) {
    ll ans = 0;
    ll mid = enemies[pos + k / 2].first;
    loop(i, pos, pos + k) {
        ll x = enemies[i].first;
        ll power = enemies[i].second;
        ans = max(ans, power / (m - abs(mid - x)));
    }
    clog << pos << "=" << ans << "; ";
    return ans;
}

void sol() {
    cin >> n >> m >> k;
    enemies.clear();
    enemies.resize(n);
    loop(i, 0, n) { cin >> enemies[i].second; }
    loop(i, 0, n) { cin >> enemies[i].first; }

    sort(enemies.begin(), enemies.end());
    loop(i, 0, n) {
        clog << enemies[i].first << "," << enemies[i].second << "; ";
    }
    clog << "\n";
    ll ans = LONG_LONG_MAX;
    loop(i, 0, n - k + 1) {
        ll pos1 = enemies[i].first;
        ll pos2 = enemies[i + k - 1].first;
        // clog << i << "." << pos1 << "-" << pos2 << "; ";
        if (pos2 - pos1 <= 2 * m + 1) {
            ans = min(ans, calc(i));
        }
    }
    cout << (ans == LONG_LONG_MAX ? -1 : ans);
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
        clog << "\n";
        cout << "\n";
    }
}
