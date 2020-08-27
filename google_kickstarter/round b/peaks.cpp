#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n;
    cin >> n;
    ll i, x, a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll c = 0;
    for (i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
            ++c;
    }
    cout << c;
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