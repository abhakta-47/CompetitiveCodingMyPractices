#include <bits/stdc++.h>

using namespace std;

#define ll int
#define pb push_back
#define loop(i, x, n) for (ll i = x; i < n; i++)

void sol() {
    ll n, m;
    cin >> n >> m;
    ll x0 = 0, x1 = n, y0 = 0, y1 = m;
    char c;
    loop(i, 0, n) loop(j, 0, m) {
        cin >> c;
        if (c == '#') {
            x0 = max(x0, i);
            x1 = min(x1, i);
            y0 = max(y0, j);
            y1 = min(y1, j);
        }
    }

    cout << (x0 + x1) / 2 + 1 << " " << (y0 + y1) / 2 + 1;

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
