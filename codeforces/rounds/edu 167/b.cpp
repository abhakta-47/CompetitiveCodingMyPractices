#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

int special_lcs(string x, string y) {
    ll n = x.size(), m = y.size();
    ll ans = 0;
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));

    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {

            if (x[j - 1] == y[i - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    for (ll i = 1; i <= m; i++)
        ans = max(ans, dp[i][n]);

    return ans;
}

void sol() {
    string a, b;
    cin >> a >> b;
    ll m = a.size(), n = b.size();

    cout << m + (n - special_lcs(a, b));

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
        clog << "\nCase #" << i + 1 << ": \n";
        sol();
        cout << "\n";
    }
}