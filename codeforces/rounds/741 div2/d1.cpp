#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, q;
    cin >> n >> q;
    string rods;
    cin >> rods;
    for (ll i = 1; i < n; i += 2)
        rods[i] = (rods[i] == '-' ? '+' : '-');
    cout << rods << " ";
    ll dp[2][n] = {0};
    memset(dp, 0, sizeof(dp));
    if (rods[0] == '-')
        dp[0][0]++;
    else
        dp[1][0]++;
    for (int i = 1; i < n; i++) {
        if (rods[i] == '-') {
            dp[0][i] = dp[0][i - 1] + 1;
            dp[1][i] = dp[1][i - 1];
        } else {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1] + 1;
        }
    }
    cout << "\n";
    for (ll i = 0; i < n; i++)
        cout << dp[0][i] << "";
    cout << "\n";
    ll l, r, t[2];
    while (q--) {
        cin >> l >> r;
        t[0] = dp[0][r] - dp[0][l - 1] + rods[l - 1] == '-' ? 1 : 0;
        cout << dp[0][r - 1] << "-" << dp[0][l - 1] << "=" << t[0] << "";
        cout << "=" << r - l + 1 - 2 * t[0] << "\n";
    }
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
