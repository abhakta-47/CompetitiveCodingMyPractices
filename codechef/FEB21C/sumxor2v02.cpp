#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll mod = 998244353;

ll modularExponentiation(ll x, ll n, ll M)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //n is even
        return modularExponentiation((x * x) % M, n / 2, M);
    else //n is odd
        return (x * modularExponentiation((x * x) % M, (n - 1) / 2, M)) % M;
}

ll modInverse(ll A, ll M)
{
    return modularExponentiation(A, M - 2, M);
}

void bitCounter(ll *a, ll &n, ll (&numBits)[2][30])
{
    ll bitPos;
    for (bitPos = 0; bitPos < 30; bitPos++)
    {
        ll highBits = 0;
        for (ll aPos = 0; aPos < n; aPos++)
        {
            if (a[aPos] % 2 == 1)
                highBits++;
            a[aPos] /= 2;
        }
        numBits[1][bitPos] = highBits;
        numBits[0][bitPos] = n - highBits;
    }
}

void getNCR(ll &n, map<ll, vector<ll>> &nCr)
{
    vector<ll> ncr;
    ncr.resize(n + 1);
    ncr[0] = 1;
    ncr[n] = 1;
    for (ll i = 1; i <= n / 2; i++)
    {
        ncr[i] = (((ncr[i - 1]) % mod) * ((n - i + 1) % mod)) % mod;
        ncr[i] = (ncr[i] % mod * (modInverse(i, mod) % mod)) % mod;
        ncr[n - i] = ncr[i];
    }
    nCr[n] = ncr;
}

ll func()
{
    ll n, i;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];

    ll numBits[2][30];
    bitCounter(a, n, numBits);
    // for (i = 0; i < 30; i++)
    //     cout << numBits[0][i] << " " << numBits[1][i] << "\n";

    map<ll, vector<ll>> nCr;
    for (i = 0; i < 30; i++)
    {
        if (nCr.find(numBits[0][i]) == nCr.end())
            getNCR(numBits[0][i], nCr);

        if (nCr.find(numBits[1][i]) == nCr.end())
            getNCR(numBits[1][i], nCr);
    }
    // for (auto im : nCr)
    // {
    //     cout << im.first << " -> ";
    //     for (i = 0; i < im.second.size(); i++)
    //         cout << im.first << "C" << i << " = " << im.second[i] << ", ";
    //     cout << "\n";
    // }

    ll ans[n + 1] = {0};
    for (ll bitPos = 0; bitPos < 30; bitPos++)
    {
        cout << bitPos << "->\n";
        for (i = 1; i <= numBits[1][bitPos] / 2; i += 2)
            for (ll j = 0; j <= numBits[0][bitPos] / 2; j++)
            {
                cout << i << "+" << j << " " << nCr[numBits[1][bitPos]][i] << "*" << nCr[numBits[0][bitPos]][j] << " ";
                ans[i + j] = (ans[i + j] % mod +
                              ((nCr[numBits[1][bitPos]][i] % mod * nCr[numBits[0][bitPos]][j] % mod) % mod *
                               (1 << bitPos) % mod) %
                                  mod) %
                             mod;
                if (0 <= (i + numBits[0][bitPos] - j) <= n)
                    ans[i + numBits[0][bitPos] - j] = ans[i + j];

                if (0 <= (numBits[1][bitPos] - i + j) <= n)
                    ans[numBits[1][bitPos] - i + j] = ans[i + j];

                if (0 <= (numBits[0][bitPos] + numBits[1][bitPos] - i - j) <= n)
                    ans[(numBits[0][bitPos] + numBits[1][bitPos] - i - j)] = ans[i + j];
                cout << ans[i + j] << "\n";
            }
    }

    for (i = 1; i <= n; i++)
    {
        cout << i << " -> " << ans[i] << "\n";
        ans[i] = (ans[i - 1] % mod + ans[i] % mod) % mod;
    }

    ll q, m;
    cin >> q;
    while (q--)
    {
        cin >> m;
        cout << ans[m] << "\n";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    t = 1;
    //cin>>t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        // cout << "\n";
    }

    ll n = 10;
}
