#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, k;
    cin >> n >> k;
    ll i;
    ll a[n];
    ll s[n / 2] = {0};
    ll c[2 * k + 1] = {0};

    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n / 2; i++)
        ++c[a[i] + a[n - i - 1]];

    ll p = 0;
    set<ll> sums;
    for (i = 0; i < 2 * k + 1; i++)
    {
        if (c[i] > c[p])
        {
            sums.clear();
            p = i;
            sums.insert(i);
        }
        else if (c[i] == c[p])
            sums.insert(i);
    }
    ll ans = 0, ansf;
    set<ll>::iterator itr;
    for (itr = sums.begin(); itr != sums.end(); ++itr)
    {
        p = *itr;
        cout << "sum " << p << "    ";
        ans = 0;
        for (i = 0; i < n / 2; i++)
        {
            if (a[i] + a[n - i - 1] != p)
            {
                if ((1 <= p - a[i] && p - a[i] <= k) || (1 <= p - a[n - i - 1] && p - a[n - i - 1] <= k))
                    ans++;
                else
                    ans += 2;
            }
            cout << ans << "  ";
        }

        if (itr == sums.begin())
            ansf = ans;
        else if (ans < ansf)
        {
            cout << " *" << *itr << " ";
            ansf = ans;
        }
    }

    cout << ansf;

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
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}