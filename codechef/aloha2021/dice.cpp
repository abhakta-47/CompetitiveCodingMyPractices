#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll MOD = 1000000007;

ll power(ll y)
{
    ll res = 1, x = 2;

    x = x % MOD;

    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

void sol()
{
    ll n;
    cin >> n;
    if (n < 4)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = (power(n) % MOD - ((2 % MOD * n % MOD) % MOD) - 2) % MOD;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        sol();
        cout << "\n";
    }
}