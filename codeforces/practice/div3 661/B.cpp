#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll func()
{
    ll n;
    cin >> n;
    ll a[n], b[n], a_min = INT_MAX, b_min = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a_min = min(a_min, a[i]);
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        b_min = min(b_min, b[i]);
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ans += max((a[i] - a_min), (b[i] - b_min));
    }
    cout << ans;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    //t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
