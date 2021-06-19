#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back


void sol(){
    int n;
    cin>>n;
    int x,i;
    int ans=0;
    for(i=0;i<n;i++){
        cin>>x;
        if(x==1||x==3)
            ++ans;
    }
    cout<<ans;

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
