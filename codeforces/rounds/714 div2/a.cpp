#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back


void sol(){
    int n,k;
    cin>>n>>k;
    //1212
    if(2*k+1>n){
        cout<<-1;
        return;
    }
    vector<int>v;
    for(int i=1;i<=(n-2*k);i++)
        v.push_back(i);
    int max=n-2*k;
    for(int i=0;i<k;i++){
        int t=v[v.size()-1];
        v.push_back(max+2);
        v.push_back(max+1);
        max+=2;
    }

    for(auto iv : v){
        cout<<iv<<" ";
    }

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
