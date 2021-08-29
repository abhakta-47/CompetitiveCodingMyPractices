#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (ll i = x; i < n; i++)

void sol() {
    ll n, k;
    cin >> n >> k;
    ll a[n], maxi = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    ll ans = 0;
    for (ll i = k - 1; i < n; i++)
        if (a[i] == maxi)
            ans += (n - i);
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
