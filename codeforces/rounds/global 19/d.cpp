#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[2][n];
    loop(i, 0, n) cin >> a[0][i];
    loop(i, 0, n) cin >> a[1][i];

    // ll psum[2][n] = {0};
    // psum[0][0] = a[0][0];
    // psum[1][0] = a[1][0];
    // loop(i, 1, n) {
    //     psum[0][i] = a[0][i] + psum[0][i - 1];
    //     psum[1][i] = a[1][i] + psum[1][i - 1];
    // }

    // loop(i, 0, n) cout << psum[0][i] << " ";
    // cout << "\n";
    // loop(i, 0, n) cout << psum[1][i] << " ";
    // cout << "\n";

    // ll t1, t2, ans = 0;
    // for (int i = 0; i < n-1; i++) {
    //     t1 = (psum[0][i - 1] * a[0][i] + psum[1][i - 1] * a[1][i]);
    //     t2 = (psum[0][i - 1] * a[1][i] + psum[1][i - 1] * a[0][i]);
    //     ans += min(t1, t2) + a[0][i] * a[0][i] + a[1][i] * a[1][i];
    //     cout << min(t1, t2) << " ";
    // }
    // cout << "\n";

    ll psum[2] = {a[0][0], a[1][0]}, t1, t2, ans = 0;
    cout << psum[0] << " " << psum[1] << "\n";
    loop(i, 1, n) {
        t1 = psum[0] * a[0][i] + psum[1] * a[1][i];
        t2 = psum[0] * a[1][i] + psum[1] * a[0][i];
        if (t1 > t2) {
            psum[0] += a[1][i];
            psum[1] += a[0][i];
        } else {
            psum[0] += a[0][i];
            psum[1] += a[1][i];
        }
        ans += min(t1, t2);
        ans += (a[0][i] * a[0][i] + a[1][i] * a[1][i]) * (n - 1);
        cout << psum[0] << " " << psum[1] << " " << min(t1, t2) << "\n";
    }

    ans += (a[0][0] * a[0][0] + a[1][0] * a[1][0]) * (n - 1);
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
