#include <bits/stdc++.h>

using namespace std;

#define dout cout
#define ll long long
#define pb push_back

void sol(){
    int n;
    cin>>n;
    int x,i;
    vector<int>a[2];

    for(i=0;i<n;i++){
        cin>>x;
        a[x%2].pb(x);
    }

    for(auto iv:a[1])
        cout<<iv<<" ";
    for(auto iv:a[0])
        cout<<iv<<" ";

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    //t=1;
    cin >> t;
    while (t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
