#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, i;
    cin >> n;
    vector<ll> x, h, a, b, t;
    x.resize(n);
    h.resize(n);
    a.resize(n);
    b.resize(n);
    //input
    int k = 2;
    if (n < 2)
        k = 1;
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> h[i];
    }

    for (i = 1; i < n - 1; i++)
    {
        if (i > 0)
        {
            if (x[i] - h[i] > x[i - 1])
                ++k;
            else if (x[i] + h[i] < x[i + 1])
            {
                x[i] = x[i] + h[i];
                ++k;
            }
        }
    }
    cout << k;
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
        //cout << "Case #" << i + 1 << ": ";
        func();
        //cout << "\n";
    }
}