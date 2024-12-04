#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, m, l;
vector<bool> hurldes;
unordered_map<ll, vector<ll>> powerups;

ll dfs(ll pos, ll powerup) {
    ll ans = LONG_LONG_MAX;
    // hurdles
    for (auto i : powerups[pos]) {
        ans = min(dfs(pos, powerup), ans);
    }

    return ans;
}

void sol() {
    cin >> n >> m >> l;

    hurldes.clear();
    powerups.clear();
    hurldes.resize(n, 1);
    loop(i, 0, n) {
        ll x, y;
        loop(j, x, y) hurldes[j] = 0;
    }

    loop(i, 0, m) {
        ll x, y;
        cin >> x >> y;
        powerups[x].pb(y);
    }
    ll ans = dfs(0, 1);
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
        // clog<<"\n";
        cout << "\n";
    }
}
