#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, x, i;
    cin >> n;
    vector<ll> sums;
    sums.push_back(0);

    for (i = 0; i < n; i++)
    {
        cin >> x;
        sums.push_back(sums[i] + x);
    }

    sort(sums.begin(), sums.end());

    ll ans = n * (n + 1) / 2;

    ll k = 1;

    for (i = 1; i <= n; i++)
    {
        //cout << sums[i] << " ";
        if (sums[i - 1] == sums[i])
            ++k;
        else
        {
            cout << k << " ";
            ans -= k * (k - 1) / 2;
            k = 1;
        }
    }
    cout << k << " ";
    ans -= k * (k - 1) / 2;

    cout << ans;

    return 0;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}