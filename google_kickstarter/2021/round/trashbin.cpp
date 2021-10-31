#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll trash[2][n];
    memset(trash, 1000000, sizeof(trash));
    if (s[0] == '1')
        trash[0][0] = 0;
    if (s[n - 1] == '1')
        trash[1][n - 1] = 0;
    for (ll i = 1; i < n; i++) {
        if (s[i] == '1')
            trash[0][i] = 0;
        else
            trash[0][i] = trash[0][i - 1] + 1;
    }
    for (ll i = n - 2; i >= 0; i--) {
        if (s[i] == '1')
            trash[1][i] = 0;
        else
            trash[1][i] = trash[1][i + 1] + 1;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        // cout << trash[0][i] << "," << trash[1][i] << ",  ";
        ans += min(trash[0][i], trash[1][i]);
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
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
