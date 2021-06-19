// https://codeforces.com/contest/1342/problem/C
#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll func2(ll lcm, ll x)
{
    ll n = 0;
    n = x / lcm * (b - a);
}
ll func()
{
    ll a, b, q;
    cin >> a >> b >> q;
    ll i;
    ll lcm = a * b / __gcd(a, b), l, r, ans;
    for (i = 0; i < q; i++)
    {
        ans = 0;
        cin >> l >> r;
        ans = (r % lcm - l % lcm - 1) * b;
        ans += (r % lcm > b) ? (r % lcm - b) : 0;
        ans -= ((l - l / lcm * lcm) > b) ? 0 : ((l - l / lcm * lcm) - b);
        cout << ans << " ";
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