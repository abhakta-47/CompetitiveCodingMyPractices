#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll sum_digits(ll x){
    ll sum=(ll)0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int func(){
    ll n;
    cin>>n;
    ll x=n;
    
    while(true){
        if(__gcd(x,sum_digits(x))!=1)
            break;
        ++x;
    }

    cout<<x;

    return 0;
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
