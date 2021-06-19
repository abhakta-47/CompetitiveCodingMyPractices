#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n], i;
    map<ll, ll> freq;
    for (i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    ll dp[n];
    map<ll, ll> presum;
    presum[a[0]]++;
    dp[0] = 0;
    for (i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1];
        if (presum.find(a[i]) != presum.end())
            dp[i] += presum[a[i]];
        presum[a[i]] += (i + 1);
        ans += dp[i];
    }

    cout << ans;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
