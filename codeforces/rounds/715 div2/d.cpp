#include <bits/stdc++.h>

using namespace std;

#define dout cout
#define ll long long
#define pb push_back

ll n;
vector<ll>a;
ll dp[2000][2000];
string mix(string s, string t, char c) {
    int n = s.size()/2;
    vector<int> v1 = {-1}, v2 = {-1};
    for(int i = 0; i < 2 * n; i++) {
        if(s[i] == c)
            v1.push_back(i);
        if(t[i] == c)
            v2.push_back(i);
    }
    string ans;
    for(int i = 0; i < n; i++) {
        for(int j = v1[i] + 1; j < v1[i + 1]; j++)
            ans += s[j];
        for(int j = v2[i] + 1; j < v2[i + 1]; j++)
            ans += t[j];
        ans += c;
    }
    for(int j = v1[n] + 1; j < 2 * n; j++)
        ans += s[j];
    for(int j = v2[n] + 1; j < 2 * n; j++)
        ans += t[j];
    return ans;
}


void sol(){
    int n, i;
    cin>>s;
    string s[3];
    vector<int>s0;
    for(i=0;i<3;i++){
        cin>>s[i];
        int c0=0;
        for(int j=0;j<2*n;j++)
            if(s[i][j]=='0')
                ++c0;
        if(c0>=n)
            s0.push_back(i);
    }

    if(s0.size()>=2)
        rec(s[0],s[1],'0');
    else
        rec(s[(s0[0]+1)%3], s[(s0[0]+2)%3],'1');
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // sol();

    ll t;
    t=1;
    // cin>>t;
    while(t--){
        // cout<<"\ntestcase"<<t<<" :: \n";
        sol();
        cout<<"\n";
    }
}
