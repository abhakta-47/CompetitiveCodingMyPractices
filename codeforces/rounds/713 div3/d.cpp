#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sol(){
    ll n;
    cin>>n;
    ll a[n],b[n+2],i;
    for(i=0;i<n+2;i++)
        cin>>b[i];
    sort(b,b+n+2);
    ll sum=0;
    for(i=0;i<n+1;i++)
        sum+=b[i];
    if(sum==2*b[n]){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            else
                cout<<b[j]<<" ";
        }
        return;
    }

    for(i=0;i<n+1;i++)
        if(sum-b[i]==b[n+1]){
            for(int j=0;j<n+1;j++){
                if(i==j)
                    continue;
                else
                    cout<<b[j]<<" ";
            }
            return;
        }

    cout<<"-1";

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