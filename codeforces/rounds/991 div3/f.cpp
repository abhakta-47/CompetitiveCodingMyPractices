#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

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


void sol() {
    ll n,q;
    cin >> n >> q;
    vector<ll>a(n);
    loop(i,0,n) cin>>a[i];
    if(n==1){
        ll l,r;
        loop(iq,0,q){
            cin>>l>>r;
            cout<<0<<" ";
        }
        return;
    }
    vector<ll>diffs(n-1);
    loop(i,0,n-1) diffs[i] = abs(a[i+1]-a[i]);
    SparseTree sptr(diffs, true);
    

    ll l,r,ans;
    loop(queries, 0, q){
        cin>>l>>r;
        ans = l==r ? 0 : sptr.query(l-1,r-2);
        cout << ans << " ";
    }
    

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
