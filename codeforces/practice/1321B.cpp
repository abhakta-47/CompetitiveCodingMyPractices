#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n;
    cin >> n;
    ll i;
    vector<ll> b;
    b.resize(n);
    for (i = 0; i < n; i++)
        cin >> b[i];

    ll ans = 0, t = 0;

    i = 1;
    ll p = 1;
    while (b.size() != 0)
    {
        if (i == b.size())
        {
            cout << "\n";
            i = 1;
            t += b[i];
            b.erase(b.begin());
            ans = max(ans, t);
            t = b[0];
        }

        if (b[i] - b[0] == i)
        {
            cout << b[i] << b[0] << " ";
            t += b[i];
            b.erase(b.begin() + i);
        }
        else
            ++i;
    }

    cout << ans;
}