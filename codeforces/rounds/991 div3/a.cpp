#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<ll>ss(n);
    string s;
    loop(i,0,n){
        cin>>s;
        ss[i] = s.length();
    }
    // sort(ss.begin(), ss.end());
    ll x=0;
    loop(i,0,n){
        if(x+ss[i]>m){
            cout<<i;
            return;
        }
        x+=ss[i];
    }
    cout<<n;

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
