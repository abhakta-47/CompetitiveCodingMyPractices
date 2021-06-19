#include<bits/stdc++.h>

using namespace std;

#define ll long long

map< int, set< pair<int,int>> >m;

void find_pair(int n,int x){

    if(m.find(x)!=m.end())
        return;
    
    for(int i=2;i<n;i++)
        for(int j=i;j<n;j++)
            if(i*j%n==x){
                m[x].insert({i,j});
                find_pair(n,i);
                find_pair(n,j);
                // cout<<i<<" "<<j<<", ";
                // pos_pair.insert({i,j});
            }
    // cout<<"\n";
    return;
}

// set<int>ans;

void concatenate(int x, set<int> Ans){
    for(auto is: m[x]){
        set<int>ans;
        ans.insert(is.first);
        ans.insert(is.second);
        concatenate(is.first, ans);
        concatenate(is.second, ans);
        if(ans.size()>Ans.size())
            Ans=ans;
        // ans.clear();
    }
}

void sol(){

    int n;
    cin>>n;
    cout<<n<<"->\n";
    m.clear();
    find_pair(n,1);
    // ans.clear();
    set<int>Ans;
    concatenate(1,Ans);
    Ans.insert(1);
    for(auto is:Ans)
        cout<<is<<" ";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        sol();
        cout<<"\n";
    }
}
