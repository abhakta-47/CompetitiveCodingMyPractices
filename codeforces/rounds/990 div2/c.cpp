#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll x,y;
    vector<ll> a1(n), a2(n);
    loop(i,0,n) cin>>a1[i];
    loop(i,0,n) cin>>a2[i];
    ll ans=0;
    ll max_el = min(a1[0], a2[0]);
    loop(i,0,n){
        ans += max(a1[i], a2[i]);
        max_el = max(max_el, min(a1[i], a2[i]));
    }
    ans += max_el;
    cout<<ans;
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
