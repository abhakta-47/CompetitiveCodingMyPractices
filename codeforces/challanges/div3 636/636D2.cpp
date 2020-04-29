#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, k;
    cin >> n >> k;
    ll i, a[n], b[n], x;

    for (i = 0; i < n / 2; i++)
        cin >> a[i];

    for (i = n / 2 - 1; i >= 0; i--)
        cin >> b[i];

    vector<ll> smax, smin;
    map<ll, ll> ssum;

    for (i = 0; i < n / 2; i++)
    {

        smin.push_back(min(a[i], b[i]) + 1);
        smax.push_back(max(a[i], b[i]) + k);
        x = (a[i] + b[i]);
        //cout << a[i] << b[i] << " ";
        if (ssum.find(x) == ssum.end())
            ssum.insert(make_pair(x, 1));
        else
        {
            ll y = ssum.find(x)->second;
            ssum.erase(x);
            ssum.insert(make_pair(x, ++y));
        }
    }

    sort(smax.begin(), smax.end());
    sort(smin.begin(), smin.end());

    ll cmin = 0, cmax = 0, ceq = 0;

    map<ll, ll>::iterator itm;

    // for (i = 0; i < n / 2; i++)
    //     cout << smax[i] << " ";
    // cout << "\n";
    // for (i = 0; i < n / 2; i++)
    //     cout << smin[i] << " ";
    // cout << "\n";

    //cout << "      ";
    // vector<int> v;
    // cout << v.begin() - lower_bound(v.begin(), v.end(), 1);
    ll ans;
    for (ll s = 2; s <= 2 * k; s++)
    {
        if (ssum.find(s) != ssum.end())
            ceq = ssum.find(s)->second;
        else
            ceq = 0;
        cmin = smin.end() - upper_bound(smin.begin(), smin.end(), s);
        cmax = lower_bound(smax.begin(), smax.end(), s) - smax.begin();
        if (s == 2)
            ans = n / 2 + cmin + cmax - ceq;
        else
            ans = min(ans, n / 2 + cmin + cmax - ceq);
        //cout << s << " " << cmin << " " << cmax << " " << ceq << " " << ans << "\n";
    }

    cout << ans;

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