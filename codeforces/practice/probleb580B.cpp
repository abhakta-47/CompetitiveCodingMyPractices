#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, d, x, y;
    cin >> n >> d;
    ll i;
    multiset< pair<ll, ll> >s;
    vector< pair<ll, ll> >v;

    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    s.insert(v[0]);
    s.insert( make_pair(0,0) );

    for (i = 1; i < n; i++)
    {
        v[i].second += v[i - 1].second;
        s.insert(v[i]);
    }

    ll m = 0;

    multiset< pair<ll, ll> >::iterator itr, itp;

    for (itr = s.begin(); itr != s.end(); itr++)
    {   
        if( itr != s.begin()){

        x = (*itr).first;
        itp = s.lower_bound(make_pair(x + d, 0));
        --itp;
    
            --itr;
        //cout<<x<<" "<<(*itr).first<<" "<<(*itr).second<<"    "<<(*itp).first<<" "<<(*itp).second<<"\n";
        m = max(m, (((*itp).second - (*itr).second)>0 ?  ((*itp).second - (*itr).second) : ((*itr).second - (*itp).second) ) );
            ++itr;
        }
    }
    
    cout<<m;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    t=1;
    //cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        //cout << "\n";
    }
}