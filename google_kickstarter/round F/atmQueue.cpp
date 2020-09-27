#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func(){
    int n,x,i,p;

    cin >> n >> x;
    vector< pair<int,int> >v;

    for(i=0;i<n;i++)
        {
           cin >> p;
           v.push_back( make_pair(ceil(p*1.0/x), i));
        }
    sort(v.begin(),v.end());
    
    for(i=0;i<n;i++)
        cout << v[i].second+1 <<" ";


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    //t=1;
    cin>>t;
    for(i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": ";
        func();
        cout<<"\n";
    }
}
