#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll MOD = 1e9 + 7;
vector<ll> pals;
vector<vector<ll>> dp;

ll get(ll x, ll p) {
    if (x < 0 || p < 0) {
        // if (pals[p] <= x)
        //     cout << x << "," << p << ":" << 0 << ", ";
        return 0;
    }
    if (p == 0 || x <= 1) {
        // if (pals[p] <= x)
        //     cout << x << "," << p << ":" << 1 << ", ";
        return 1;
    }
    return dp[x][p];
}

void sol() {
    ll x;
    cin >> x;
    cout << dp[x][pals.size() - 1];
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll nlimit = 4 * 1e4;
    loop(i, 1, 10) pals.push_back(i);                                   // i
    loop(i, 1, 10) pals.push_back(i * 10 + i);                          // ii
    loop(i, 1, 10) loop(j, 0, 10) pals.push_back(i * 100 + j * 10 + i); // iji
    loop(i, 1, 10) loop(j, 0, 10)
        pals.push_back(i * 1000 + j * 100 + j * 10 + i); // ijji

    loop(i, 1, 10) loop(j, 0, 10) loop(k, 0, 10) {
        ll x = (i * 10000 + j * 1000 + k * 100 + j * 10 + i) % MOD;
        if (x <= nlimit)
            pals.push_back(x); // ijji
    }
    sort(pals.begin(), pals.end());
    // cout << pals.size() << " " << pals[pals.size() - 1] << " " << nlimit
    //      << ":: ";

    dp.clear();
    dp.resize(nlimit + 1, vector<ll>(pals.size(), 0));
    loop(i, 1, nlimit + 1) {
        dp[i][0] = 1;
        loop(j, 1, pals.size()) dp[i][j] =
            (get(i, j - 1) % MOD + get(i - pals[j], j) % MOD) % MOD;
    }
    // cout << dp[1][0] << ":" << dp[1][497];
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
