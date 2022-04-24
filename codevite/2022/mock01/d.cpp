#include <bits/stdc++.h>

using namespace std;

#define ll int
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, b, h;
    cin >> n >> b >> h;
    ll g[n];
    loop(i, 0, n) cin >> g[i];
    ll dp[2][n] = {0};
    stack<ll> s, t;
    s.push(g[0]);
    dp[0][0] = 0;
    dp[1][n - 1] = 0;
    for (int i = 1; i < n; i++) {
        dp[0][i] = 0;
        while (!s.empty() && s.top() >= g[i]) {
            t.push(s.top());
            s.pop();
            dp[0][i]++;
        }
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        s.push(g[i]);
    }
    while (!s.empty())
        s.pop();
    s.push(g[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        dp[1][i] = 0;
        while (!s.empty() && s.top() >= g[i]) {
            // cout << g[i];
            t.push(s.top());
            s.pop();
            dp[1][i]++;
        }
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        s.push(g[i]);
        // cout << " ";
    }
    // cout << "\n";
    ll ans = 0, total = 0;
    for (ll i = 0; i < n; i++) {
        // cout << g[i] << ",";
        total += g[i];
        // cout << dp[0][i] << " " << dp[1][i] << ", ";
        ans = max(ans, (dp[0][i] + dp[1][i] + 1) * g[i]);
    }
    // cout << total << " " << ans << " ";
    cout << (total - ans) * b * h;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
