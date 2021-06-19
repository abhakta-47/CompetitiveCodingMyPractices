#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll MOD=1000000007; 


void sol(){

    ll n,k;
    cin>>n>>k;
    ll ans=(ll)1;
    // cout<<n<<" "<<k<<"\n";
    for(int i=1;i<=k;i++)
        ans = (ans * n)%MOD;
    cout<<ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    while(t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
