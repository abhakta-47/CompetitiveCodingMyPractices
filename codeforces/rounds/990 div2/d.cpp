#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    loop(i,0,n) cin>>a[i];
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    loop(i,0,n) pq.push({a[i],i});
    ll left_max=pq.top().second, right_pos=n-1;
    while(pq.size()){
        ll val = pq.top().first;
        ll pos = pq.top().second;
        pq.pop();
        if( pos >= left_max ){
            cout << val << " ";
            left_max = max(left_max, pos);
        }
        else
            pq.push({val+1,++right_pos});
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
        clog << "Case #" << i + 1 << ": \n";
        sol();
        clog<<"\n";
        cout << "\n";
    }
}
