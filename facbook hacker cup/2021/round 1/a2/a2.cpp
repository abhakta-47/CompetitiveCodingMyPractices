#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)
ll MOD = (1e9 + 7);

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    char lastChar = s[0];
    ll dp[n] = {0}, ans = 0, lastPos = 0;

    for (ll i = 1; i < n; i++) {
        switch (s[i]) {
        case 'F':
            dp[i] = dp[i - 1];
            break;
        case 'O':
            if (lastChar == 'X')
                dp[i] = ((dp[i - 1] % MOD + lastPos % MOD) % MOD + 1) % MOD;
            else
                dp[i] = dp[i - 1];
            lastChar = 'O';
            lastPos = i;
            break;
        default:
            if (lastChar == 'O')
                dp[i] = ((dp[i - 1] % MOD + lastPos % MOD) % MOD + 1) % MOD;
            else
                dp[i] = dp[i - 1];
            lastChar = 'X';
            lastPos = i;
            break;
        }
        // dp[i] += dp[i - 1];
        // cout << s[i] << dp[i] << " ";
        ans = (ans % MOD + dp[i] % MOD) % MOD;
    }
    cout << ans;

    return;
}

int main() {
    // cout << MOD;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
