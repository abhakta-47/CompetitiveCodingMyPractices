#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    x = x > a ? x - a : 0;
    y = y > b ? y - b : 0;
    if (x + y <= c)
        cout << "YES";
    else
        cout << "NO";

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
