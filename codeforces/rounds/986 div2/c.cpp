#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, m, v;
    cin >> n >> m >> v;
    clog << n << " " << m << " " << v << "\n";

    vector<ll>a(n+2, 0);
    loop(i,1,n+1) cin >> a[i];

    vector<ll>pre_sum(n+2,0);
    loop(i,1,n+2) pre_sum[i] = pre_sum[i-1] + a[i];

    vector<ll>pre(n+2,0), post(n+2,0);
;
    ll cur=0;
    for(ll i=1; i<=n; i++){
        cur += a[i];
        pre[i] = pre[i-1];
        if( cur>=v ){
            pre[i]++;
            cur=0;
        }
    }
    pre[n+1] = pre[n];
    cur = 0;
    for(ll i=n; i>=1; i--){
        cur += a[i];
        post[i] = post[i+1];
        if( cur>=v ){
            post[i]++;
            cur=0;
        }
    }
    post[0] = post[1];
    ll rp=0, ans=-1;
    for(int lp=0; lp<=n; lp++){
        ll x = pre[lp];
        clog << lp<<"="<<pre[lp];
        ll target = m-x;
        clog << "." << target << ".";
        for(;post[rp]>=target && rp<=n; ++rp);
        clog << rp<<"="<<post[rp] << ".";
        if(post[rp]<target && 0<rp ) --rp;
        clog << rp<<"="<<post[rp] <<"=>";
        if( post[rp]>=target ) ans = max(ans, pre_sum[rp-1]-pre_sum[lp] );
        clog << ans << "; ";
    }
    cout << ans;
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
