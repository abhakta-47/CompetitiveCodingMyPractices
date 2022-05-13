#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

inline ll get_adj_num(ll x, ll y) {
    ll ans = 0, k;
    while (x > 0 || y > 0) {
        if (x < y)
            swap(x, y);
        k = x - y;
        if (k >= y) {
            ans += ceil(x / 2.0);
            break;
        }
        if (k == 0) {
            ans += ceil((x + y) / 3.0);
            break;
        }
        ans += k;
        x -= 2 * k;
        y -= k;
    }

    return ans;
}

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    ll ans = get_adj_num(a[0], a[1]);
    // cout << ans;
    loop(i, 0, n - 1) { ans = min(ans, get_adj_num(a[i], a[i + 1])); }
    loop(i, 1, n - 1) {
        ans = min(ans, (ll)(max(a[i - 1], a[i + 1])));
        if (a[i - 1] % 2 && a[i + 1] % 2)
            ans = min(ans, a[i - 1] / 2 + a[i + 1] / 2 + 1);
    }
    sort(a, a + n);
    if (ans < (ceil(a[0] / 2.0) + ceil(a[1] / 2.0)))
        cout << ans;
    else
        cout << (ceil(a[0] / 2.0) + ceil(a[1] / 2.0));
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
        // clog<<"\n";
        cout << "\n";
    }
}
