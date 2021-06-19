#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n], b[n], x = 0, y = 0;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    for (ll i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;
        else if (a[i] == 1)
            ++x;
        else if (b[i] == 1)
            ++y;
    }

    if (x == 0)
        cout << -1;
    else
        cout << y / x + 1;
}