#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = a[0];
    for (int i = 1; i < n; i++)
        ans &= a[i];
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
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
