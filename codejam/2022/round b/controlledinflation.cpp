#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll getval(ll l1, ll r1, ll l2, ll r2) {
    cout << l1 << " " << r1 << ", " << l2 << " " << r2 << "=";
    ll ans;
    if (r1 <= l2) {
        ans = (l2 - l1);
    } else if (r2 <= l1) {
        ans = (l1 - l2);
    } else {
        ans = min(abs(r2 - l1), abs(r1 - l2));
    }
    cout << ans << ", ";
    return ans;
}

void sol() {
    ll n, p;
    cin >> n >> p;
    ll a[n][p];
    loop(i, 0, n) {
        loop(j, 0, p) { cin >> a[i][j]; }
        sort(a[i], a[i] + p);
    }
    loop(i, 0, n) { a[i][1] = a[i][p - 1]; }
    ll ans = 0, dp[n][2] = {0};
    for (ll i = n - 2; i >= 0; i--) {
        dp[i][0] = (min(dp[i + 1][0] + abs(a[i][0] - a[i + 1][1]),
                        dp[i + 1][1] + abs(a[i][0] - a[i + 1][0])) +
                    abs(a[i + 1][0] - a[i + 1][1]));
        dp[i][1] = (min(dp[i + 1][0] + abs(a[i][1] - a[i + 1][1]),
                        dp[i + 1][1] + abs(a[i][1] - a[i + 1][0])) +
                    abs(a[i + 1][0] - a[i + 1][1]));
    }
    // loop(i, 0, n) {
    //     cout << a[i][0] << "," << dp[i][0] << " " << a[i][1] << "," <<
    //     dp[i][1]
    //          << "\n";
    // }
    cout << min(dp[0][0] + a[0][1], dp[0][1] + a[0][0]) + a[0][1] - a[0][0];
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
        cout << "Case #" << i + 1 << ": ";
        sol();
        cout << "\n";
    }
}
