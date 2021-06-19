#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, k;
    cin >> n >> k;
    ll a[n], c[n] = {0};
    ll i;
    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i] && a[i + 1] < a[i])
            c[i] = 1;
    }

    for (i = 1; i < n; i++)
        c[i] += c[i - 1];

    ll p = 0;

    for (i = 0; i <= (n - k + 1); i++)
    {
        if ((c[i + k - 2] - c[i]) > (c[p + k - 2] - c[p]))
            p = i;
        }

    cout << c[p + k - 2] - c[p] + 1 << " " << p + 1;

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