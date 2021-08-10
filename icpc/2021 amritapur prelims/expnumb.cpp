#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol2(vector<ll> &v, ll n, ll X)
{
    ll m = v.size();
    ll table[n + 1];
    ll ans = LLONG_MAX;
    table[0] = (ll)0;

    for (ll i = 1; i <= n; i++)
        table[i] = LLONG_MAX;

    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j < m; j++)
            if (v[j] <= i)
            {
                ll sub_res = table[i - v[j]];
                if (sub_res != LLONG_MAX)
                    table[i] = min(table[i], sub_res + 1);
                if (n - X <= i && i != n)
                {
                    // cout << table[i];
                    if (table[i] != LLONG_MAX)
                        ans = min(ans, table[i] + 1);
                }
                if (i == n)
                {
                    // cout << table[i];
                    ans = min(ans, table[i]);
                }
            }

    if (ans == LLONG_MAX)
        cout << -1;
    else
        cout << ans;
}

void sol()
{
    ll n, x;
    cin >> n >> x;
    ll t = n, t2 = 0, k = 0, t3 = 1;
    vector<ll> v;
    while (t)
    {
        if (k % 2 == 1)
            v.push_back(t3);
        ++k;
        t3 *= 2;
        t /= 2;
    }

    if (x == n)
        cout << 1;
    else
        sol2(v, n, x);

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
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
