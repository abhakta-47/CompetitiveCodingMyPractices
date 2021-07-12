#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back

void sol()
{
    ll n, m;
    cin >> n >> m;
    ll x, y;
    set<ll> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (ll j = x; j <= y; j++)
            s.insert(j);
    }
    ll ans[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> x;

        auto is = s.lower_bound(x);
        ll t1 = *is;
        ll t2 = *(--is);
        if (t1 == x)
        {
            ans[i] = t1;
            s.erase(t1);
        }
        else
        {
            swap(t1, t2);
            // cout << t1 << " " << x << " " << t2 << "\n";
            if ((x - t1) <= (t2 - x))
            {
                ans[i] = t1;
                s.erase(t1);
            }
            else
            {
                ans[i] = t2;
                s.erase(t2);
            }
        }
    }
    for (auto ia : ans)
        cout << ia << " ";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        sol();
        cout << "\n";
    }
}
