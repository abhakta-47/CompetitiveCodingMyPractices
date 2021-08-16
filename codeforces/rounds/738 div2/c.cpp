#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[n - 1] == 0) {
        for (int i = 0; i <= n; i++)
            cout << i + 1 << " ";
        return;
    }
    if (a[0] == 1) {
        cout << n + 1 << " ";
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
        return;
    }
    ll x = -1;
    for (int i = 0; i < n - 1; i++) {
        // cout << a[i] << " ";
        if (a[i] == 0 && a[i + 1] == 1) {
            x = i;
            // break;
        }
    }
    if (x == -1) {
        cout << x;
        return;
    }
    // cout << x << " : ";
    for (int i = 0; i <= x; i++)
        cout << i + 1 << " ";
    cout << n + 1 << " ";
    for (int i = x + 1; i < n; i++)
        cout << i + 1 << " ";
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
