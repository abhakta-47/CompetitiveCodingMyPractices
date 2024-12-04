#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll find_x(ll n) {
    // max x such that, 2*x + r = n && x is perfect square
    if (n == 1) {
        cout << "-1";
        return -1;
    }
    if (n == 2) {
        cout << "1 1 ";
        return 1;
    }
    ll m = n / 2;
    ll x = pow((ll)sqrt(m), 2);
    ll r = n - 2 * x;
    ll xr = find_x(r);
    if (xr == -1) {
        return -1;
    }
    ll rt = xr + x;
    loop(i, xr + 1, rt + 1) cout << i << " ";
    loop(i, xr + 1, rt + 1) cout << i << " ";
    return rt;
}

void sol() {
    ll n;
    cin >> n;
    find_x(n);
    cout << "\n";

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
