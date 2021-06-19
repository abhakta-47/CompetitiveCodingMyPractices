#include<bits/stdc++.h>

using namespace std;
#define ll long long

void func(){
    ll n;
    cin>>n;
    ll a[n], i;
    for(i=0;i<n;i++)
        cin>>a[i];

    if(n<2){
        cout<<"0";
        return;
    }

    ll m,c,s;
    s=a[0];
    c=a[1]-a[0];
    set<ll>mk;
    for(i=1;i<n;i++)
        mk.insert(c+a[i-1]-a[i]);

    if(mk.size()==1){
        cout<<"0";
        return;
    }
    ll ans=*mk.begin();
    for(auto is:mk){
        // cout<<is<<", ";
        ans=__gcd(ans,is);
    }
    // cout<<"\n";

    if(ans<0)
        cout<<"-1";
    else
        cout<<ans<<" "<<c;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout<<"\n";
    }
}
