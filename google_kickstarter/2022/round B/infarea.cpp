#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll r, a, b;
    cin >> r >> a >> b;
    ll ans = 0;
    double pi = 3.1415927;
    while (r) {
        ans += r * r;
        r = r * a;
        ans += r * r;
        r = r / b;
    }
    cout << fixed;
    cout << setprecision(6);
    // cout << ans << ": " << pi << ": ";
    cout << pi * (ans * 1.0);
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
        cout << "Case #" << i + 1 << ": ";
        sol();
        cout << "\n";
    }
}
