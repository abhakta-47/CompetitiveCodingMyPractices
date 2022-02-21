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

    if (a[n - 2] > a[n - 1]) {
        cout << -1 << "\n";
        return;
    }
    // pos pos, neg pos, (neg neg && an-1 <= a[n])
    if (a[n - 1] >= 0) {
        cout << n - 2 << "\n";
        loop(i, 0, n - 2) cout << i + 1 << " " << n - 1 << " " << n << "\n";

    } else {
        // neg
        loop(i, 0, n - 1) {
            if (a[i] > a[i + 1]) {
                cout << -1 << "\n";
                return;
            }
        }
        cout << 0 << "\n";
    }

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
        // cout << "\n";
    }
}
