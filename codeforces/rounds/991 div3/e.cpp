#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)


void sol() {
    string a,b,c;
    cin >> a >> b >> c;

    a = " " + a;
    b = " " + b;
    c = " " + c;
    ll na=a.length(), nb=b.length(), nc=c.length();


    vector<vector<ll>>dp(na+1,vector<ll>(nb+1,LONG_MAX));
    dp[0][0] = 0;
    for(ll ia=0; ia<na; ia++){
        for(ll ib=0; ib<nb; ib++){
            dp[ia+1][ib] = min( dp[ia+1][ib], dp[ia][ib] + (a[ia+1]==c[ia+ib+1] ? 0 : 1));
            dp[ia][ib+1] = min( dp[ia][ib+1], dp[ia][ib] + (b[ib+1]==c[ia+ib+1] ? 0 : 1));
        }
    }
    dp[na][nb] = min(dp[na-1][nb], dp[na][nb-1]);
    cout << dp[na][nb];
    loop(i,0,na+1){
        loop(j,0,nb+1) clog << dp[i][j] << ", ";
        clog<<"\n";
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
