#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool contains(int x, int y, vector< pair<int,int>>v){
    for(int i=0;i<4;i++)
        if(x==v[i].first && y==v[i].second)
            return true;
    return false;
}

void sol(){
    int n;
    cin>>n;
    vector< pair<int,int> >v;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            if(c=='*')
                v.push_back({i,j});
        }

    // cout<<v[0].first<<" "<<v[0].second<<"\n";
    // cout<<v[1].first<<" "<<v[1].second<<"\n";
    pair<int,int> p1=v[0],p2=v[1];

    if( p1.first!=p2.first && p1.second!=p2.second){
        v.push_back({p1.first, p2.second});
        v.push_back({p2.first, p1.second});
    }
    else if( p1.first==p2.first ){
        int x=(p1.first==0?1:0);
        v.push_back({x, p1.second});
        v.push_back({x, p2.second});
    }
    else{
        int y=(p1.second==0?1:0);
        v.push_back({p1.first, y});
        v.push_back({p2.first, y});
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( contains(i,j,v) )
                cout<<"*";
            else
                cout<<".";
        }
        cout<<"\n";
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
        // cout<<"\n";
    }
}