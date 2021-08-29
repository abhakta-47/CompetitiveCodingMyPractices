#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[n], b[n - 1];
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n - 1) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n - 1);

    if (n == 2) {
        if ((b[0] - a[0]) > 0 && (b[0] - a[1]) > 0)
            cout << min(b[0] - a[0], b[0] - a[1]);
        else if ((b[0] - a[0]) > 0)
            cout << b[0] - a[0];
        else
            cout << b[0] - a[1];
        return;
    }

    ll d1, d2, ans1 = LONG_LONG_MAX, ans2 = LONG_LONG_MAX;

    ll total1 = 0, total2 = 0;
    loop(i, 0, n) total1 += a[i];
    loop(i, 0, n - 1) total2 += b[i];
    ll diff = total2 - total1; // = (n-1)*x - el;
    // cout << diff << " ";
    // 0 removed
    d1 = b[0] - a[1];
    d2 = b[1] - a[2];
    if (d1 == d2)
        ans1 = min(ans1, d1);
    // 1 removed
    d1 = b[0] - a[0];
    d2 = b[1] - a[2];
    if (d1 == d2)
        ans1 = min(ans1, d1);
    // other removed
    d1 = b[0] - a[0];
    d2 = b[1] - a[1];
    if (d1 == d2)
        ans1 = min(ans1, d1);

    for (auto it : a)
        if ((diff + it) % (n - 1) == 0)
            if ((diff + it) / (n - 1) > 0)
                ans2 = min(ans2, (diff + it) / (n - 1));

    cout << max(ans1, ans2);

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
