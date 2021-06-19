#include <bits/stdc++.h>

using namespace std;

#define dout cout
#define ll long long
#define pb push_back

ll n;
vector<ll>a;
ll dp[2000][2000];
ll rec(ll l,ll r){
    // cout<<l<<","<<r<<"-> ";

    if(dp[l][r]!=-1)
        return dp[l][r];

    ll diff=a[r]-a[l], ans;
    if(l<r)
        ans=diff+min( rec(l+1,r), rec(l,r-1) );
    else
        ans=diff;
    
    // cout<<"\n"<<"("<<l<<","<<r<<")= ";
    // cout<<ans<<"\n";

    dp[l][r]=ans;
    return ans;
}


void sol(){
    for(int i=0;i<2000;i++)
        for(int j=0;j<2000;j++)
            dp[i][j]=-1;
    cin>>n;
    a.resize(n);
    ll i;
    for(i=0;i<n;i++)
        cin>>a[i];

    if(n==1){
        cout<<0;
        return;
    }

    sort(a.begin(),a.end());
    ll minDif=1e9, p=0;
    for(i=0;i<n-1;i++)
        if( a[i+1]-a[i]<minDif ){
            p=i;
            minDif=a[p+1]-a[p];
        }
    ll ans=rec(0,n-1);
    cout<<ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // sol();

    ll t;
    t=1;
    // cin>>t;
    while(t--){
        // cout<<"\ntestcase"<<t<<" :: \n";
        sol();
        cout<<"\n";
    }
}
