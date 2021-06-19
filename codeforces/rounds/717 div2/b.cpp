#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll x, y, i;
    ll dp_l[n], dp_r[n];

    dp_l[0] = a[0];
    for (i = 1; i < n; i++)
        dp_l[i] = a[i] ^ dp_l[i - 1];

    dp_r[n - 1] = a[n - 1];
    for (i = n - 2; i >= 0; i--)
        dp_r[i] = a[i] ^ dp_r[i + 1];

    for (i = 0; i < n - 1; i++)
    {
        // cout << dp_l[i] << " " << dp_r[i] << ", ";
        if (dp_l[i] == dp_r[i + 1])
        {
            cout << "YES";
            return;
        }
    }

    for (i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            x = dp_l[i];
            y = dp_r[j];
            int z = dp_l[i] ^ dp_l[j - 1];
            if (x == y && y == z)
            {
                // cout << i << " " << j << " ";
                cout << "YES";
                return;
            }
        }

    cout << "NO";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
