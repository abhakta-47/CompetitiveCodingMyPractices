#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

// void myGcd(ll p){
// start from p
// continue with p
// eand at p
//
// }

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];
    vector<ll> d;
    loop(i, 0, n - 1) d.push_back(abs(a[i + 1] - a[i]));
    // for (auto id : d)
    // cout << id << ", ";
    // cout << "\n";
    ll dp[n - 1], x;
    for (ll i = 0; i < n - 1; i++) {
        x = d[i];
        dp[i] = 1;
        // cout << i << "->";
        for (ll j = i; j >= 0; j--) {
            x = __gcd(d[j], x);
            // cout << x << ", ";
            if (x == 1) {
                // dp[i] = i - j;
                break;
            }
            ++dp[i];
        }
        // cout << " = " << dp[i] << "\n";
    }
    ll ans = 0;
    for (auto ix : dp)
        ans = max(ans, ix);
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
        // clog<<"\n";
        cout << "\n";
    }
}
