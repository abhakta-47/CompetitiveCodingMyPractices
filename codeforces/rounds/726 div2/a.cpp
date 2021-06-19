#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int sol(){
    int n;
    cin>>n;
    int a[n],s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }

    if(s==n)
        return 0;
    if(s<n+1)
        return 1;
    else 
        return s-n;


    return 0;
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
        cout<<sol();
        cout<<"\n";
    }
}
