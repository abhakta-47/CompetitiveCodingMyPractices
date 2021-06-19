#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol(){
    ll n;
    cin>>n;
    ll h[n];
    for(int i=0;i<n;i++)
        cin>>h[i];
    sort(h,h+n);
    
    ll minDif=h[1]-h[0];
    for(int i=1;i<n-1;i++)
        minDif = min( minDif, h[i+1]-h[i]);

    if(minDif == h[1]-h[0])
        swap(h[1],h[n-1]);
    else if( minDif == h[n-1]-h[n-2])
        swap(h[0],h[n-2]);
    else{
        for(int i=0; i<n-1;i++)
            if(minDif == h[i+1]-h[i]){
                swap(h[0], h[i]);
                swap(h[i+1], h[n-1]);
                swap(h[i], h[i+1]);
            }
    }
    for(auto hi : h)
        cout<<hi<<" ";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
