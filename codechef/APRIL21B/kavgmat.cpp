#include<bits/stdc++.h>

using namespace std;

#define ll long long

void pre_sum_matrix(ll **a, ll **sum, ll n, ll m){
    ll i,j;
    for(i=0;i<n;i++){
        sum[i][0]=a[i][0];
        for(j=1;j<m;j++)
            sum[i][j]=a[i][j]+sum[i][j-1];
    }

    for(j=0;j<m;j++)
        for(i=1;i<n;i++)
            sum[i][j]+=sum[i-1][j];
}

void display_matrix(ll **a, ll n, ll m){
    ll i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

bool avg_matrix(ll **sum,ll x,ll y,ll l,ll k){
    ll actualSum;
    if(x==0 && y==0)
        actualSum= sum[x+l-1][y+l-1];
    else if(x==0)
        actualSum= sum[x+l-1][y+l-1]
                    -sum[x+l-1][y-1];
    else if(y==0)
        actualSum= sum[x+l-1][y+l-1]
                    -sum[x-1][y+l-1];
    else
        actualSum= sum[x+l-1][y+l-1]
                    -sum[x+l-1][y-1]
                    -sum[x-1][y+l-1]
                    +sum[x-1][y-1];
    // cout<<actualSum<<","<<actualSum<<","<<l*l;
    return ( actualSum>=k*l*l ? true : false );
}

void sol(){

    ll n,m,k;
    cin>>n>>m>>k;
    ll i,j;
    ll **a;
    a=new ll *[n];
    for(i=0;i<n;i++)
        a[i]=new ll[m];
    
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>a[i][j];

    ll **sum;
    sum=new ll *[n];
    for(i=0;i<n;i++)
        sum[i]=new ll[m];
    pre_sum_matrix(a,sum,n,m);
    
    ll ans=0;
    for(ll l=1;l<=min(n,m);l++){
        // cout<<l<<"->\n";
        ll jRange=m-l+1;
        for(i=0; i+l-1<n; i++){
            // cout<<i<<"- ";
            for(j=0; j<jRange; j++){
                // cout<<j<<". ";
                if(avg_matrix(sum,i,j,l,k)){
                    // cout<<i<<","
                    //     <<j<<" "
                    //     <<(n-l-i+1)<<"*"<<(jRange-l-j+1)<<" "
                    //     <<(n-l-i+1)*(jRange-l-j+1)<<"\n";
                    ans+=(n-l-i+1)*(jRange-l-j+1);
                    jRange=j+1;
                    break;
                }
                // cout<<" ";
            }
            // cout<<"\n";
        }
    }

    cout<<ans;

    return;            
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
