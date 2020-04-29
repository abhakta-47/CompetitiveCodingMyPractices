#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n;
    cin >> n;
    ll i, x;
    ll y, m;
    cin >> y;
    m = y;
    ll ans = 0;
    for (i = 1; i < n; i++)
    {
        cin >> x;
        if (x * y > 0)
        {
            m = max(m, x);
        }
        else
        {
            ans += m;
            m = x;
        }
        y = x;
    }
    ans += m;
    cout << ans;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}