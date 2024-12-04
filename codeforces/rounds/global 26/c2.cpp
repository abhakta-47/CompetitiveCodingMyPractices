#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n), maxa(n);
    loop(i, 0, n) { cin >> a[i]; }
    maxa[n - 1] = a[n - 1];
    for (int i = n - 2; i > 0; i--) {
        maxa[i] = max(a[i], maxa[i + 1]);
    }
    ll c = 0;
    loop(i, 0, n) {
        c += a[i];
        if (c < 0 && (i == n - 1 || maxa[i + 1] > 0))
            c = abs(c);
    }
    cout << abs(c);
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
