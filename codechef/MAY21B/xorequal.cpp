#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
ll MOD = 1e9 + 7;
ll power(ll x)
{
    if (x == 0)
        return (ll)1;
    if (x == 1)
        return (ll)2;
    ll t = power(x / (ll)2);
    if (x % 2)
        return ((ll)2 % MOD * t % MOD * t % MOD) % MOD;
    return (t % MOD * t % MOD) % MOD;
}

void sol()
{
    ll n;
    cin >> n;
    cout << power(n - 1);
    return;
}

// int printTest(int x){

// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
