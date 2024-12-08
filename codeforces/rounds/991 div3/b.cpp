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
    ll sum[2] = {0};
    loop(i,0,n){
        sum[i%2] += a[i];
    }
    if( sum[0]%((ll)ceil(n/2.0))==0 && sum[1]%(n/2)==0 && sum[0]/((ll)ceil(n/2.0))==sum[1]/(n/2)  )
        cout<<"YES";
    else
        cout<<"NO";
    

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
