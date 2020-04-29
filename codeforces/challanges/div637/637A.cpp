#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, a, b, c, d, a1, b1, c1, d1;
    cin >> n >> a1 >> b1 >> c1 >> d1;
    a = n * (a1 + b1);
    b = n * (a1 - b1);
    c = c1 + d1;
    d = c1 - d1;
    if ((a >= c && c >= b) || (a <= c && d <= a))
        cout << "YES";
    else
    {
        cout << "NO";
    }

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