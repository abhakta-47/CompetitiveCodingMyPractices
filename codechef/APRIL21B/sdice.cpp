#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sol(){

    ll n;
    cin>>n;
    // cout<<n<<" : ";
    if(n==1)
        cout<<20;
    else if(n==2)
        cout<<36;
    else if(n==3)
        cout<<51;
    else if(n==4)
        cout<<60;
    else if(n%4==1)
        cout<<(n/4-1)*44+ 11*1+ 15*3 +20;
    else if(n%4==2)
        cout<<(n/4-1)*44+ 11*2+ 15*2 +36;
    else if(n%4==3)
        cout<<(n/4-1)*44+ 11*3+ 15*1 +51;
    else if(n%4==0)
        cout<<(n/4-1)*44+ 11*4+ 15*0 +60;

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
