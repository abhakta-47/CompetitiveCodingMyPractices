// AC :)
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll MAX = 1001;

ll get_a(ll x, ll y)
{
    return ((x * (x + 1) / 2) +
            (x * (y - 1)) +
            ((y - 2) * (y - 1) / 2));
}

void sol()
{

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll ans = 0;
    for (ll i = x1; i <= x2; i++)
    {
        // cout << i << " " << y1 << " =" << get_a(i, y1) << ", ";
        ans += get_a(i, y1);
    }
    // cout << "\n";
    for (ll i = y1 + 1; i <= y2; i++)
    {
        // cout << x2 << " " << i << " =" << get_a(x2, i) << ", ";
        ans += get_a(x2, i);
    }
    // cout << "\n";

    cout << ans;
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
