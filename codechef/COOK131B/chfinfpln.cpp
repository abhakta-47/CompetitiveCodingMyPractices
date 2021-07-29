#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n = 0;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        ll x = 0;
        cin >> x;
        arr.pb(x);
    }
    unordered_map<ll, ll> um;
    for (int i = 0; i < n; i++)
    {
        um[arr[i]]++;
    }
    ll ans = 0;
    for (auto x : um)
    {
        ll l = x.first;
        ll m = x.second;
        if (m < l)
            ans += m;
        else
            ans += (l - 1);
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
