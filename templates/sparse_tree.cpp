#include <bits/stdc++.h>

using namespace std;

#define ll long long

class SparseTree {
    public:
    ll numSeeds;
    ll overlapAllowed;
    vector<ll>bin_log;
    vector<vector<ll>>table;
    ll sparseOperator(ll x, ll y){
        if(x==0 && y==0) return 0;
        return __gcd(x,y);
    }
    void buildTree(){
        ll n = this->numSeeds;
        for(ll level=1; level<=log2(n); level++){
            table[level].resize(n-(1<<level)+1);
            for(ll i=0; i+(1<<level) <= n; ++i)
                table[level][i] = sparseOperator(table[level-1][i], table[level-1][i+(1<<(level-1))]);
        }
    }
    SparseTree(vector<ll>seeds, bool overlapAllowed=true){
        ll n = seeds.size();
        this->overlapAllowed = overlapAllowed;
        this->numSeeds = n;
        this->table.resize(log2(n)+1);
        this->table[0].resize(n);
        for(ll i=0; i<numSeeds; i++)
            table[0][i] = seeds[i];
        buildTree();

        bin_log.resize(n+1);
        bin_log[0] = 0;
        bin_log[1] = 0;
        for(ll i=2; i<=n; i++) bin_log[i] = bin_log[i/2] + 1;
    }
    ll query(ll l, ll r){
        if(!overlapAllowed) throw "not implemented";
        ll diff = r - l + 1;
        ll level = bin_log[diff];
        ll x = this->table[level][l];
        ll y = this->table[level][r-(1<<level)+1];
        return sparseOperator(x, y);
    }
};
