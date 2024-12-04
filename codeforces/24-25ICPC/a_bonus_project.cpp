#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (ll i = x; i < n; i++)

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n) cin >> b[i];

    vector<ll> c(n + 1, 0), pre(n + 1, 0);
    for (ll i = n - 1; i >= 0; i--) {
        c[i] = a[i] / b[i];
        pre[i] = c[i] + pre[i + 1];
    }
    // loop(i, 0, n) clog << c[i] << "." << pre[i] << "; ";
    ll curk = 0;
    for (int i = 0; i < n; i++) {
        if (k - curk > pre[i]) {
            cout << "0 ";
            continue;
        }
        ll x = max((ll)0, ((k - curk) - pre[i + 1]));
        curk += x;
        cout << x << " ";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog << "\n";
        cout << "\n";
    }
}
