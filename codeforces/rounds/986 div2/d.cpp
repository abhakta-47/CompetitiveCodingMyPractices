#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n;
vector<pair<ll,char>>t1,tn;

void special_sort(const vector<ll>&v, char c){
    ll pr_n, pr_1;
    pr_1 = v[0];
    pr_n = v[n-1];
    for(int i=0; i<n; i++){
        if( v[i]<pr_1 && 1<i+1 ) t1.push_back({i+1, c});
        if( v[i]>pr_n && i+1<n ) tn.push_back({i+1, c});
    }
}

void sol() {
    cin >> n;
    t1.clear();
    tn.clear();
    vector<ll> queen(n), king(n), jack(n);
    loop(i,0,n) cin >> queen[i];
    loop(i,0,n) cin >> king[i];
    loop(i,0,n) cin >> jack[i];

    loop(i,0,n) clog << queen[i] << " "; clog<<"\n";
    loop(i,0,n) clog << king[i] << " "; clog<<"\n";
    loop(i,0,n) clog << jack[i] << " "; clog<<"\n";
    
    special_sort(queen, 'q');
    special_sort(king, 'k');
    special_sort(jack, 'j');

    for(auto i1 : t1){
        ll c1 = i1.first;
        if(c1==n){
            cout<<"YES\n1\n";
            cout << i1.second << " " << n << "\n";
            return;
        }
    }
    for(auto in: tn){
            ll cn = in.first;
            if(cn==1){
                cout<<"YES\n1\n";
                cout << in.second << " " << n << "\n";
                return;
            }
    }
    sort(t1.begin(), t1.end());
    sort(tn.begin(), tn.end());
    for(auto i1 : t1){
        ll c1 = i1.first;
        pair<ll,char> search_key = {c1, 'a'};
        auto in = lower_bound(tn.begin(), tn.end(), search_key);
        for(;in!=tn.end(); ++in){
            ll cn = in->first;
            if(c1==cn){
                cout<<"YES\n2\n";
                cout << i1.second << " " << c1 << "\n";
                cout << in->second << " " << n << "\n";
                return;
            }

            if( queen[c1-1] > queen[cn-1] && c1<cn ){
                cout << "YES\n3\n";
                cout << i1.second << " " << c1 << "\n";
                cout << "q" << " " << cn << "\n";
                cout << in->second << " " << n << "\n";
                return;
            }
            if( king[c1-1] > king[cn-1] && c1<cn ){
                cout << "YES\n3\n";
                cout << i1.second << " " << c1 << "\n";
                cout << "k" << " " << cn << "\n";
                cout << in->second << " " << n << "\n";
                return;
            }
            if( jack[c1-1] > jack[cn-1] && c1<cn ){
                cout << "YES\n3\n";
                cout << i1.second << " " << c1 << "\n";
                cout << "j" << " " << cn << "\n";
                cout << in->second << " " << n << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
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
        clog << "Case #" << i + 1 << ": \n";
        sol();
        clog<<"\n";
        // cout << "\n";
    }
}
