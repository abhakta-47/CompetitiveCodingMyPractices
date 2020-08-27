#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, d;
    cin >> n >> d;
    ll i, a[n];
    for (i = n - 1; i >= 0; i--)
        cin >> a[i];

    for (i = 0; i < n; i++)
    {
        d = (d / a[i]) * a[i];
    }
    cout << d;
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
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}