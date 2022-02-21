#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];
    ll ans = 0;
    if (n == 2)
        ans = 0;
    else
        loop(i, 1, n - 1) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                a[i + 1] = (i + 2 < n ? max(a[i], a[i + 2]) : a[i]);
                ++i;
                ++ans;
            }
        }
    cout << ans << "\n";
    loop(i, 0, n) cout << a[i] << " ";

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
