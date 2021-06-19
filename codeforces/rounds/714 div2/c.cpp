#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll MOD = 1e9 + 7;
vector<ll> dp;
ll rec(ll m)
{
    if (dp[m] != -1)
        return dp[m];
    if (m < 0)
        dp[m] = 1;
    else
        dp[m] = (rec(m - 9) + rec(m - 10)) % MOD;
    return dp[m];
}

void sol()
{
    ll n, m;
    cin >> n >> m;

    dp.clear();
    dp.resize(m, -1);
    for (int i = 0; i < min(m, (ll)9); i++)
        dp[i] = 2;
    dp[9] = 3;
    for (ll i = 10; i <= m; i++)
        dp[i] = dp[i - 9] + dp[i - 10];
    ll ans = 0;
    while (n > 0)
    {
        int x = n % 10;
        ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
        // cout << x << "-" << ((m + x < 10) ? 1 : rec(m + x - 10)) << ", ";
        ans %= MOD;
        n /= 10;
    }

    cout << ans;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, i;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
