#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back


void sol(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll primes1[9]={ 2, 11, 101, 1019, 10007, 100003, 1000003, 10000019, 818752171};
    ll primes2[9]={ 3, 13, 103, 1009, 10009, 100019, 1000009, 10000169, 825753601};
    string xcs[10]={"","0","00","000","0000","00000","000000","0000000","00000000","000000000"};

    ll Xc = pow(10,c-1);
    ll Xa = primes1[a-c]*Xc;
    ll Xb = primes2[b-c]*Xc;

    cout<<Xa<<" "<<Xb;

    return;            
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i;
    cin>>t;

    while(t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
