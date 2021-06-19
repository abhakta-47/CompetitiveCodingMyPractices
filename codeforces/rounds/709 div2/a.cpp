#include<bits/stdc++.h>

using namespace std;
#define ll long long

int func(){
    int a,b;
    cin>>a>>b;
    cout<<a*b;

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
