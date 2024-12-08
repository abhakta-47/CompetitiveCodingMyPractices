#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string n;
    cin >> n;
    ll mod3=0;
    ll f2=0, f6=0;
    for(auto ia:n){
        mod3 = ((ia-'0')+mod3)%9;
        if(ia=='2') f2++;
        if(ia=='3') f6++;
    }
    for(ll i=0; i<=min((ll)9, f2); i++){
        for(ll j=0; j<=min((ll)9, f6); j++){
            if( (mod3+(i*2)%9+(j*6%9))%9==0 ){
                cout<<"YES";
                return;
            }
        }
    }
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
