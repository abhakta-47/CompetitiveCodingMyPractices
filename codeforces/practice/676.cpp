#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, k, i, l, m = 0;
    string s;
    cin >> n >> k >> s;
    ll a = 0, b = 0;
    vector<pair<ll, ll> > counter;
    counter.push_back(make_pair(a, b));
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
            ++a;
        else
            ++b;
        counter.push_back(make_pair(a, b));
    }

    ll flag = 0;

    for (l = 1; l <= s.length(); l++)
    {
        flag = 0;
        for (i = 0; i <= s.length() - l; i++)
        {
            a = counter[i + l].first - counter[i].first;
            b = counter[i + l].second - counter[i].second;
            //cout<<l<<"* ";
            if (min(a, b) <= k)
            {   
                //cout<<i<<" "<<i+l<<"   ";
                m = l;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    cout <<m;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    t=1;//cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}