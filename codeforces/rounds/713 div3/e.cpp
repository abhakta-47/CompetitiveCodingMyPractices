#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back


void sol(){
    int n, l, r, s, i;
    cin>>n>>l>>r>>s;

    int sPart[r-l+1], curSum=0;
    for(i=0;i<r-l+1;i++){
        sPart[i]=i+1;
        curSum+=(i+1);
    }

    if(s<curSum){
        cout<<"-1";
        return;
    }
    /*
    5
    4 1
    3 2 1
    10
    9 1
    8 2 1
    7 3 2 1
    3 4 3 2 1 invalid
    */
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
