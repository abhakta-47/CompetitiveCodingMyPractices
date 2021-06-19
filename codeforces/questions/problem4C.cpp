#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    cout<<"in";
    ll n, i, s = 0;
    cin >> n;
    ll a[n];
    ll k = 0;
    cin >> a[0];
    for (i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == -1 && a[i - 1] != -1)
        {
            s += a[i - 1];
            ++k;
        }
        if (a[i] != -1 && a[i - 1] == -1)
        {
            s += a[i];
            ++k;
        }
    }

    cout << s / k;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << "in";
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}
