#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll MOD = (1e9 + 7);
vector<ll> dp;

inline ll nbits(ll x) { return (ll)log2(x) + 1; }

void sol() {
    ll n, p;
    cin >> n >> p;
    ll a[n], __max = 0;
    loop(i, 0, n) {
        cin >> a[i];
        a[i] = p - nbits(a[i]);
        __max = max(__max, a[i]);
    }
    loop(i, 0, n) cout << a[i] << ", ";
    cout << "\n";
    dp.clear();
    dp.resize(__max + 2, 1);
    dp[1] = 2;
    loop(i, 2, n + 2) dp[i] =
        (1 + (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD) % MOD;
    loop(i, 0, n + 2) cout << dp[i] << ", ";
    cout << "\n";
    ll ans = 0;
    loop(i, 0, n) { ans = (ans + dp[a[i]] % MOD) % MOD; }
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
