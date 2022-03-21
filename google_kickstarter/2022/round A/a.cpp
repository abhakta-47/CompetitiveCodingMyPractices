#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string si, sp;
    cin >> si >> sp;
    ll ni = si.length(), np = sp.length();
    ll ii = 0, ip = 0;
    while (ii < ni && ip < np) {
        // cout << ii << " " << ip;
        if (si[ii] == sp[ip]) {
            // cout << ".";
            ++ii;
        }
        ++ip;
        // cout << ", ";
    }
    // cout << ii << " " << ip << " = ";
    if (ii == ni || ii > ni)
        cout << np - ni;
    else
        cout << "IMPOSSIBLE";
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
