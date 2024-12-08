#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n,b,c;
    cin >> n >> b >> c;

    if(b==0){
        if(c>=(n-2) && (n-2)>0) cout << n-1;
        else cout<<-1;
        return;
    }

    // smallest c
    if(c>=n){
        cout<<n;
        return;
    }

    // b*0+c .... b*(n-1)+c
    // b*i+c <= n-1
    ll i = b==0 ? (1) : (n-1-c)/b;
    cout << (n-i-1);

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
