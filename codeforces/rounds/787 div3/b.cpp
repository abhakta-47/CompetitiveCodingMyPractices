#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll update(ll &x, ll &y) {
    // cout << x << " ";
    ll ans = pow((x / y + 1), 0.5);
    x = x / pow(2, ans);
    if (x >= y) {
        ++ans;
        x /= 2;
    }
    // cout << ans << "=" << x << ", ";
    return ans;
}

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];
    ll ans = 0, t;
    if (n != 1 && a[n - 1] == 0) {
        cout << -1;
        return;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1])
            ans += update(a[i], a[i + 1]);
        if (a[i] == 0 && i != 0) {
            cout << "-1";
            return;
        }
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
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
