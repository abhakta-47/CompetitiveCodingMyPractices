#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, m;
    string s;
    cin >> n >> s >> m;
    // cout << s << "\n";
    ll nums[m];
    loop(i, 0, m) cin >> nums[i];
    ll dp[2][n], l, r;
    for (int i = 0; i < n; i++) {
        dp[1][i] = 1;
        l = i - 1;
        r = i + 1;
        while (0 <= l && r < n) {
            // cout << s[l] << s[r] << ",";
            if (s[l] != s[r])
                break;
            dp[1][i] += 2;
            --l;
            ++r;
        }
        dp[0][i] = 0;
        l = i;
        r = i + 1;
        while (0 <= l && r < n) {
            // cout << s[l] << s[r] << ",";
            if (s[l] != s[r])
                break;
            dp[0][i] += 2;
            --l;
            ++r;
        }
        // cout << dp[0][i] << " " << dp[1][i];
        // cout << "\n";
    }

    ll ans = 0;
    loop(i, 0, m) {
        loop(j, 0, n) {
            if (dp[nums[i] % 2][j] >= nums[i]) {
                // cout << j << ",";
                ++ans;
            }
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
