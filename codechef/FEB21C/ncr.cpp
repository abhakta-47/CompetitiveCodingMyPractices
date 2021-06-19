#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
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

void getNCR(ll &n, map<ll, vector<ll>> &nCr)
{
    vector<ll> ncr, ncr1;
    ncr.resize(n + 1);
    ncr1.resize(n + 1);
    ncr[0] = 1;
    ncr1[0] = 1;
    ncr[n] = 1;
    ncr1[n] = 1;
    for (ll i = 1; i <= n / 2; i++)
    {
        // ncr[i] = (((ncr[i - 1]) % mod * (n - i + 1) % mod) % mod * modInverse(i, mod) % mod) % mod;
        // ncr[i] = (ncr[i - 1] * (n - i + 1) / i) % mod;
        ncr1[i] = (((ncr1[i - 1]) % mod) * ((n - i + 1) % mod)) % mod;
        ncr1[i] = (ncr1[i] % mod * (modInverse(i, mod) % mod)) % mod;
        // cout << i << "-> "
        //      << (ncr1[i - 1]) % mod << "*"
        //      << (n - i + 1) % mod << "/"
        //      << i << " ("
        //      << modInverse(i, mod) % mod << ") *1= "
        //      << ((ncr1[i - 1]) % mod) * ((n - i + 1) % mod) % mod << " " << (((ncr1[i - 1]) % mod) * ((n - i + 1) % mod) < mod) << "  "
        //      << ncr1[i] << " \n";
        ncr[n - i] = ncr[i];
        ncr1[n - i] = ncr1[i];
    }
    nCr[n] = ncr;
}

int main()
{
    map<ll, vector<ll>> nCr;
    ll n = 100;
    getNCR(n, nCr);
}