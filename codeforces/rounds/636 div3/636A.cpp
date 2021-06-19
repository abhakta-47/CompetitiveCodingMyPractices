#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n;
    cin >> n;
    ll i = 1, s = 0;
    ll y, x, l = 1, maxl = 0, maxs = -999999999;
    ll flag = 0;
    cin >> y;
    s = y;
    set<pair<ll, ll>> v;
    for (i = 1; i < n; i++)
    {
        cin >> x;
        if (y * x < 0)
        {
            ++l;
            s += x;
        }
        else
        {
            cout << l << " " << s << "   ";
            v.insert(make_pair(l, s));
            l = 1;
            s = x;
        }
        y = x;
    }
    cout << l << " " << s << "   ";

    cout << maxs;
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