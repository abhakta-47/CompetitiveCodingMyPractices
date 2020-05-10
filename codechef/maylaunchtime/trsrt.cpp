#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, k;
    cin >> n >> k;
    ll a[n + 1] = {0}, p[n + 1] = {0};
    ll x, i;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = x;
        p[x] = i;
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
        //cout<<"\n";
    }
}