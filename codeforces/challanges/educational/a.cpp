// works :)
// https://codeforces.com/contest/1342/problem/A
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll p;
    if (2 * a > b)
    {
        p = a * (max(x, y) - min(x, y));
        p += min(x, y) * b;
    }
    else
        p = a * (x + y);

    cout << p;

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