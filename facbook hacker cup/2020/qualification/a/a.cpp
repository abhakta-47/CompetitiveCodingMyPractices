#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    string in, out;
    cin >> in >> out;
    // ll dp[2][n - 1];
    // for (int i = 0; i < n; i++) {
    //     if (out[i] == 'Y' && in[i + 1] == 'Y')
    //         dp[0][i] = 1;
    //     if (in[i] == 'Y' && out[i + 1] == 'Y')
    //         dp[1][i + 1] = 1;
    // }
    char ans[n][n];
    memset(ans, 'N', sizeof(ans));
    for (int i = 0; i < n; i++) {
        ans[i][i] = 'Y';
        for (int j = i; j < n - 1; j++) {
            if (out[j] == 'Y' && in[j + 1] == 'Y')
                ans[i][j + 1] = 'Y';
            else
                break;
            // cout << i << j + 1 << ans[i][j + 1] << " ";
        }
        // cout << "\n";
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cout << ans[i][j];
    //     cout << "\n";
    // }
    for (int i = n - 1; i >= 0; i--) {
        ans[i][i] = 'Y';
        for (int j = i; j > 0; j--)
            if (out[j] == 'Y' && in[j - 1] == 'Y')
                ans[i][j - 1] = 'Y';
            else
                break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << "\n";
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
        cout << "Case #" << i + 1 << ":\n";
        sol();
        // clog<<"\n";
        // cout << "\n";
    }
}
