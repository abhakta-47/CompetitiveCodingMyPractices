#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back


void sol(){

    ll n,q;
    cin>>n>>q;

    ll x,i;
    ll topPos[51]={0};
    for(i=1;i<=n;i++){
        cin>>x;
        if(topPos[x]==0)
            topPos[x]=i;
    }

    // for(ll j=1;j<=50;j++)
    //     if(topPos[j]!=0)
    //         cout<<j<<"->"<<topPos[j]<<", ";
    // cout<<"\n";  

    // ll t;
    for(i=0;i<q;i++){
        cin>>x;
        ll ans=topPos[x];
        topPos[x]=1;
        // cout<<x<<" ";
        cout<<ans<<" ";
        for(int j=1;j<=50;j++)
            if(topPos[j]<ans && topPos[j]!=0 && j!=x)
                topPos[j]++;
        // for(ll j=1;j<=50;j++)
        //     if(topPos[j]!=0)
        //         cout<<j<<"->"<<topPos[j]<<", ";
        // cout<<"\n";        
    }

    return;            
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i;
    // cin>>t;
    t=1;
    while(t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
