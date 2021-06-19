#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    ll i;
    ll ans = 0;
    ll x;
    ll k12 = 0, k13 = 0, k21 = 0, k23 = 0, k31 = 0, k32 = 0;
    for (i = 1; i <= k1 + k2 + k3; i++)
    {
        cin >> x;
        if (i <= k1)
        {
            if (k1 + k2 < x)
                ++k13;
            else if (k1 < x)
                ++k12;
        }
        else if (k1 < i && i <= k1 + k2)
        {
            if (x <= k1)
                ++k21;
            else if (k1 + k2 < x)
                ++k23;
        }
        else if (i > k2 + k1)
        {
            if (x <= k1)
                ++k31;
            else if (x <= k1 + k2)
                ++k32;
        }
    }

    ans += min(k13, k31);
    ans += min(k12, k21);
    ans += min(k23, k32);

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    t = 1;
    //cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}