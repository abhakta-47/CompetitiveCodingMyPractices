#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
ll MOD = 1e9 + 7;

void sol()
{
    ll n, k;
    cin >> n >> k;
    ll nSame = 1, t = n - 1;
    for (int i = 1; i < n; i++)
        nSame = (nSame % MOD * 2 % MOD) % MOD;
    if (!(n & 1))
        nSame = (nSame % MOD - 1) % MOD;
    cout << nSame << ": ";
    nSame = ((n % 2 != 0) % MOD + nSame % MOD) % MOD;
    ll nLarge = (n % 2 == 0);
    ll nSmall = ((nSame % MOD - (n % 2 != 0) % MOD) % MOD - nLarge % MOD) % MOD;
    ll same = nSame, larger = nLarge, smaller = nSmall, t1, t2, t3;
    cout << same << " " << larger << ", ";
    t = k - 1;
    while (t-- > 0)
    {
        t1 = (nSame % MOD * same % MOD) % MOD;
        t2 = (nSame % MOD * larger % MOD) % MOD + (nLarge % MOD * ((same % MOD + smaller % MOD) % MOD + larger % MOD) % MOD) % MOD;
        t3 = (nSame % MOD * smaller % MOD) % MOD + (nSmall % MOD * ((same % MOD + smaller % MOD) % MOD + larger % MOD) % MOD) % MOD;
        same = t1;
        larger = t2;
        smaller = t3;
        cout << same << " " << larger << ", ";
    }
    if (k == 0)
        cout << 1;
    else if (k == 1)
        cout << nSame;
    else
        cout << (same % MOD + larger % MOD) % MOD;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
