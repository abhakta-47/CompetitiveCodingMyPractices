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
    for (i = 0; i < n; i++)
        cin >> x[i] >> h[i];
    //leftie & rightie
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            a[i] = 1;
        else if (x[i - 1] < (x[i] - h[i]))
        {
            a[i] = 1;
        }
        else
            a[i] = 0;

        if (i == n - 1)
            b[i] = 1;
        else if ((x[i] + h[i]) < x[i + 1])
            b[i] = 1;
        else
            b[i] = 0;
    }

    // for (i = 0; i < n; i++)
    //     cout << " i" << i << " a" << a[i] << " b" << b[i] << " ";

    ll k1 = 0, k2 = 0;
    //leftie and rightie
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
            k1++;
        else
        {
            if (b[i] == 1)
            {
                if (i == n - 1)
                    ++k1;
                else if (a[i + 1] == 0)
                    ++k1;
                else if (x[i] + h[i] < x[i + 1] - h[i + 1])
                    ++k1;
            }
        }
        if (b[i] == 1)
            k2++;
        else
        {
            if (a[i] == 1)
            {
                if (i == 0)
                    ++k2;
                else if (b[i - 1] == 0 && i > 0)
                    ++k2;
                else if (x[i - 1] + h[i - 1] < x[i] - h[i])
                    ++k2;
            }
        }
    }

    //cout << k1 << " " << k2;
    cout << max(k1, k2);

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
        //cout << "Case #" << i + 1 << ": ";
        func();
        //cout << "\n";
    }
}