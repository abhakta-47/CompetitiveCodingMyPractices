#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<ll, ll> m;
    int t, k;
    for (int i = 0; i < n; i++)
    {
        t = a[i];
        k = 0;
        // cout << a[i] << "= ";
        while (t)
        {
            // cout << k << ":" << t % 2 << " ";
            if (t % 2)
                ++m[k];
            else
                m[k] += 0;
            ++k;
            t /= 2;
        }
        // cout << "\n";
    }
    k = 1;
    ll ans = 0, sum = 0;
    for (auto im : m)
    {
        // cout << im.first << " " << im.second << "\n";
        ans += k * ((im.second == n) ? 1 : 0);
        k *= 2;
    }

    for (auto ix : a)
    {
        // cout << (ix | ans) << " ";
        sum |= (ix ^ ans);
    }

    cout << ans << " " << sum;

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
