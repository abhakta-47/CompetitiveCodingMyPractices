#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n;
    cin >> n;
    ll i, x, y = 0;
    map<ll, ll> m;
    vector<ll> p;
    p.push_back(0);
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        y += x;
        if (x == 0)
        {
            // p.push_back(i);
            // m.clear();
            // m.insert(make_pair(y, i));
            continue;
        }
        else if (m.find(y) == m.end())
            m.insert(make_pair(y, i));
        else
        {
            p.push_back(m.find(y)->second);
            p.push_back(i);
            m.clear();
            m.insert(make_pair(y, i));
        }
    }
    if (*(--p.end()) != n && x != 0)
        p.push_back(n);
    for (i = 0; i < p.size(); i++)
        cout << p[i] << " ";

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