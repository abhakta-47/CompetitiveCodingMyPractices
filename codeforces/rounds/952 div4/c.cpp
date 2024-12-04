#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long int
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, 0, n) cin >> a[i];
    vector<ll> maxa(n, 0);
    maxa[0] = a[0];
    for (int i = 1; i < n; i++) {
        maxa[i] = max(maxa[i - 1], a[i]);
    }
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == (ll)2 * maxa[i]) {
            // cout << i << ":" << sum <<? ":" << maxa[i] << " ";
            ans++;
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
