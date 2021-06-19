#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll MOD=10e9+7;
ll mypows[31]={0};

ll myPow(int x){
    // cout<<x<<"->"<<mypows[x]<<"\n";
    return mypows[x];
}

void sol(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    pair<ll,ll> bitCounter1[31], bitCounter2[31];

    // cout<<"*"<<myPow(30)<<"\n";
    // cout<<"*"<<myPow(10)<<"\n";
    // return;

    for(int i=0;i<31;i++){
        int c0=0,c1=0;
        for(int j=a;j<=b;j++){
            if( (j/myPow(i))%2 )
                ++c1;
            else
                ++c0;
        }
        bitCounter1[i]={c0,c1};
    }
    for(int i=0;i<31;i++){
        int c0=0,c1=0;
        for(int j=c;j<=d;j++){
            if( (j/myPow(i))%2 )
                ++c1;
            else
                ++c0;
        }
        bitCounter1[i]={c0,c1};
    }

    ll ans=0;
    for(int i=0;i<31;i++){
        ans+= bitCounter1[i].first * bitCounter2[i].second;
        ans+= bitCounter1[i].second * bitCounter2[i].first;
    }
    cout<<ans;
}

void dec2bin(int x){
    vector<int>v;
    cout<<setfill('0')<<setw(3)<<x<<"-> ";
    while(x){
        v.pb(x%2);
        x/=2;
    }
    cout<<setfill('0')<<setw(8-v.size());
    for(int i=v.size()-1; i>=0; i--)
        cout<<v[i];
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);


    for(int i=10;i<=100;i++)
        dec2bin(i);

    return 0;


	int t;
    mypows[0]=(ll)1;
    for(t=1;t<31;t++){
        mypows[t]=(2*mypows[t-1])%MOD;
    }
    
    cin >> t;
    while(t--){
        sol();
        cout<<"\n";
    }
}