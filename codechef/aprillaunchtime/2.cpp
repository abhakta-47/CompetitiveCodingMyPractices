#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp push_back

int func()
{
    ll n, k;
    cin >> n >> k;
    ll i, x;
    multiset<pair<ll, ll>> s;

    for (i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(make_pair(x, i % k));
    }

    multiset<pair<ll, ll>>::iterator itr;
    ll i = 0;
    bool flag = true;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        if (itr->second != i)
            flag = false;
        if (flag == false)
            break;
        if (++i = k)
            i = 0;
    }

    if (flag)
        cout << "true";
    else
        cout << "false";

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