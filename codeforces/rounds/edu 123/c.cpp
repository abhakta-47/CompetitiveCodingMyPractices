#include <bits/stdc++.h>

using namespace std;

#define ll int
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, x;
    cin >> n >> x;
    ll a[n];
    loop(i, 0, n) { cin >> a[i]; }
    vector<ll> dp[n];
    loop(i, 0, n) {
        // O(n^2)
        // dp[i].push_back(0);
        dp[i].push_back(a[i]);
        for (int j = i - 1; j >= 0; j--)
            dp[i].push_back(dp[i][i - j - 1] + a[j]);
    }
    // loop(i, 0, n) {
    //     for (auto iv : dp[i])
    //         cout << iv << " ";
    //     cout << "\n";
    // }
    ll dp2[n];
    loop(i, 0, n) {
        dp2[i] = dp[n - 1][i];
        loop(j, 0, n) {
            if (dp[j].size() > i)
                dp2[i] = max(dp2[i], dp[j][i]);
        }
    }
    // loop(i, 0, n) cout << dp2[i] << ", ";
    // cout << "\n";
    ll ans = 0, curans;
    loop(t, 0, n + 1) {
        curans = 0;
        loop(i, max(t - 1, 0), n) {
            curans = max(dp2[i] + x * t, curans);
            // cout << dp[i][j] + x * t << ",";
        }
        ans = max(ans, curans);
        cout << ans << " ";
    }
    // cout << "\n";
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
