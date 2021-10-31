#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    char lastChar = s[0];
    ll dp[n] = {0};
    for (int i = 1; i < n; i++) {
        if (s[i] == 'F')
            dp[i] = dp[i - 1];
        else {
            if ((s[i] == 'X' && lastChar == 'O') ||
                (s[i] == 'O' && lastChar == 'X'))
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1];
            lastChar = s[i];
        }
        // cout << dp[i] << " ";
    }

    cout << dp[n - 1];

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
        // clog<<"\n";
        cout << "\n";
    }
}
