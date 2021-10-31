#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

#define arrayin(n) for (int i = 0; i < n; i++)
#define array2din(n, m)                                                        \
    for (int i = 0; i < n; i++)                                                \
        for (int j = 0; j < m; j++)
#define loop(i, x, n) for (int i = x; i <= n; i++)

void sol() {
    ll m;
    cin >> m;
    ll a[2][m];
    array2din(2, m) cin >> a[i][j];

    ll preSum[2][m + 1];
    preSum[0][m] = 0;
    preSum[1][m] = 0;
    preSum[0][m - 1] = a[0][m - 1];
    preSum[1][m - 1] = a[1][m - 1];
    for (int i = m - 2; i >= 0; i--) {
        preSum[0][i] = preSum[0][i + 1] + a[0][i];
        preSum[1][i] = preSum[1][i + 1] + a[1][i];
    }
    ll alice = 0, bob = 0, curSum = 0, breakPoint;
    ll row0, row1, ans = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        row0 = preSum[0][i + 1];
        row1 = preSum[1][0] - preSum[1][i];
        // clog << i << " = " << preSum[0][i + 1] << ", " << preSum[1][0] << " - "
        //      << preSum[1][i] << "\n";

        ans = min(ans, max(row0, row1));
    }

    // cout << max(row0, row1);
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
        // clog << "\n";
        cout << "\n";
    }
}
