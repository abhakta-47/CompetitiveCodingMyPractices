#include <bits/stdc++.h>
using namespace std;

#define ll long long

void sol()
{
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll min1 = 5 * m, max1 = 55 * m;
    // cout << max1;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        if (a[i] % 5 == 0 && min1 <= a[i] && a[i] <= max1)
            ++ans;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        sol();
        cout << "\n";
    }
}