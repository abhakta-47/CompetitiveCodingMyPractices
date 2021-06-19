#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int findTrailingZeros(ll n)
{
    // Initialize result
    ll count = (ll)0;
 
    // Keep dividing n by powers of
    // 5 and update count
    for (ll i = 5; n / i >= 1; i *= 5)
        count += n / i;
 
    return count;
}

ll find_xs(ll n, ll x){
    ll count=(ll)0;
    while(n%x==0){
        ++count;
        n/=x;
    }
    return count;
}

void func(){
    ll n=390625;
    // ll n=15;
    // ll totalZero=findTrailingZeros(n);
    // cout<<totalZero<<"\n";
    ll x=n;
    ll ans=0;
    ll twos=(ll)0, fives=(ll)0;
    for(ll i=1;i<=n;i++){
        // ll curZero=findTrailingZeros(n-i);
        twos+=find_xs(x,2);
        fives+=find_xs(x,5);
        ans+=min(twos,fives);
        cout<<i<<"-> "
            <<x<<"  "
            <<twos<<" "
            <<fives<<"   "
            <<min(twos,fives)<<"\n";
        x=n-i;
    }
    cout<<ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    // cin>>t;
    t=1;
    for(i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout<<"\n";
    }
}
