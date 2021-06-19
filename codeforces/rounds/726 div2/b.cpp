#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll distance(ll x1, ll y1, ll x2, ll y2){
    ll __distance=0;
    __distance += (x1 > x2 ? x1-x2 : x2-x1);
    __distance += (y1 > y2 ? y1-y2 : y2-y1);

    return __distance;
}

ll distance(pair<ll,ll> p1, pair<ll,ll>p2){
    return distance( p1.first, p1.second, p2.first, p2.second );
}

ll distance( pair<ll,ll> p1, pair<ll,ll>p2, pair<ll,ll>p3 ){
    ll __distance=0;
    __distance += distance(p1,p2);
    __distance += distance(p2,p3);
    __distance += distance(p3,p1);
    return __distance;
}

void sol(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    pair<ll,ll> corners[4]={ {1,1}, {n,1}, {1,m}, {n,m} };
    ll maxDis=0, maxPols[2];
    for(ll i=0;i<4; i++)
        for(ll j=i; j<4; j++)
        {
            ll distance_ = distance( {i,j}, corners[i], corners[j] );
            if( distance_ > maxDis)
            {
                maxDis = distance_;
                maxPols[0] = i;
                maxPols[1] = j;
            }
        }
    cout << corners[ maxPols[0] ].first << " "
         << corners[ maxPols[0] ].second << " "
         << corners[ maxPols[1] ].first << " "
         << corners[ maxPols[1] ].second << " ";
    // cout<<maxDis;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
