#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n, k = 1;
ll calc(ll x)
{
    cout << k << "k-x" << x << " ";
    if (k == n)
    {
        //cout << "    " << k << n << "     ";
        return x;
    }
    if (x % (n - 1) != 0)
        return 0;
    else
    {
        ++k;
        calc(n * (x / (n - 1)) + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 100;
    ll t;
    for (ll i = 0; i < 18446744073709551615; i++)
    {
        k = 1;
        t = calc(n * i + 1);
        cout << "\n";
        if (t != 0)
            break;
    }

    cout << "\nans " << t << "\n\n";
}