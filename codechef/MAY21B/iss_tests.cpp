#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll sumFactors(ll x)
{
    ll sum = 0;
    for (ll i = 1; i <= sqrt(x); i++)
        if (x % i == 0)
            sum += (i + x / i);
    return sum;
}

void sol()
{
    int lk = 1e2;
    // for (int k = 1; k < lk; k++)
    // {
    int k = 11;
    cout << k << ": ";
    clog << k << ": ";
    ll s = 0;
    map<ll, ll> m;
    ll t;
    for (int i = 1; i <= 2 * k; i++)
    {
        // clog << i << " ";
        t = __gcd((k + i * i), (k + (i + 1) * (i + 1)));
        s += t;
        if (t == 3)
            clog << i << " gcd(" << k + i * i << "," << (k + (i + 1) * (i + 1)) << ")" << t << ", ";
        m[t]++;
    }
    clog << t;
    clog << " =" << s << " = ";
    for (auto im : m)
        clog << im.first << "*" << im.second << "+ ";
    clog << "\n";
    cout << s << "\n";
    // }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    //cin>>t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
