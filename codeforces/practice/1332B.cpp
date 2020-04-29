#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n;
    cin >> n;
    ll a[n], ans[n], i;
    ll prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    set<ll> s;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        for (ll j = 0; j < 11; j++)
            if (a[i] % prime[j] == 0)
            {
                ans[i] = j + 1;
                s.insert(ans[i]);
                break;
            }
    }
    cout << s.size() << "\n";
    set<ll>::iterator itr;
    map<ll, ll> m;
    ll k = 0;
    for (i = 0; i < n; i++)
    {
        if (m.find(ans[i]) != m.end())
            cout << (m.find(ans[i])->second) << " ";
        else
        {
            m.insert(make_pair(ans[i], ++k));
            cout << k << " ";
        }
    }
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