#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, 0, n) { cin >> a[i]; }
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = abs(a[0]);
    dp[0][1] = a[0];
    ll a1, a2, a3, a4;
    loop(i, 1, n) {
        a1 = dp[i - 1][0] + a[i];
        a2 = dp[i - 1][1] + a[i];
        a3 = abs(a1);
        a4 = abs(a2);

        dp[i][0] = max(a3, a4);
        dp[i][1] = min(a1, a2);
        // cout << dp[0][0] << " " << dp[0][1] << ":::";
    }q
    cout << max(dp[n - 1][0], abs(dp[n - 1][1]));
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
