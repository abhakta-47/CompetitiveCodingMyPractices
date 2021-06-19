#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    map<ll, ll> freq[k];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[i % k][a[i]]++;
    }

    ll ans = 0;
    for (ll i = 0; i < k; i++)
    {
        ll total = 0, max_ = 0;
        for (auto freq_ : freq[i])
        {
            total += freq_.second;
            max_ = max(max_, freq_.second);
        }
        ans += (total - max_);
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
