#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n;
    cin >> n;
    ll i, x;
    vector<pair<ll, ll> > v;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        v.push_back(make_pair(x, i));
    }

    sort(v.begin(), v.end());
    ll p, per[n + 1] = {0}, c[n + 1] = {1}, j, max1 = 0, carry;
    for (i = 0; i < n; i++)
    {

        x = v[i].first;
        p = v[i].second;
        per[p] = x;
        carry = c[p];
        c[p] = 0;
        cout << x << p << " ";
        if (c[p] != max1)
        {
            cout << " n " << c[p] << " " << max1 << "n ";
            cout << "NO";
            return 0;
        }

        for (j = p + 1; j <= n; j++)
        {
            if (per[j] == 0)
            {
                c[j] += carry;
                if (c[j] > max1)
                {
                    cout << " m" << max1 << " " << c[j] << " m ";
                    max1 = c[j];
                }
                break;
            }
        }

        if (carry == max1)
        {
            max1 = 0;
            for (i = 0; i <= n; i++)
            {
                max1 = max(max1, c[i]);
            }
        }

        cout << " e ";
    }
    //cout<<" out yes";
    cout << "YES";

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