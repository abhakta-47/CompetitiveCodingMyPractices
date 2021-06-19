#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sol(){
    int n;
    cin>>n;
    int i, a[n],ans=-1;
    map<int,int>m;
    for(i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    int diff;
    for(auto im:m)
        if(im.second==1)
            diff=im.first;
    for(i=0;i<n;i++)
        if(a[i]==diff){
            cout<<i+1;
            break;
        }
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