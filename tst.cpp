#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func(){

    int x,y;
    x=5;y=2;
    if(x>3){
        if(y>3)
            continue;
        cout << "hi";
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    t=1;
    //cin>>t;
    for(i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout<<"\n";
    }
}
