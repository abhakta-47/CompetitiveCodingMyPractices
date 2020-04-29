#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll l, r, i, j;
    cin >> l >> r;
    set<ll> s;
    bool f;
    for (i = l; i <= r; i++)
    {

        f = true;
        j = i;
        s.clear();
        while (j > 0)
        {
            if (s.find(j % 10) == s.end())
                s.insert(j % 10);
            else
            {
                //cout << j << " ";
                f = false;
                break;
            }
            j /= 10;
        }
        if (f)
            break;
    }
    if (f)
        cout << i;
    else
        cout << -1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    t = 1; //cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}