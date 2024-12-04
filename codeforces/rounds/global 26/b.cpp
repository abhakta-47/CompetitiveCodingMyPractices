#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll x;
    cin >> x;
    // cout << x << "\t\t\t";
    if (x % 10 == 9) {
        cout << "NO";
        return;
    }
    x /= 10;
    while (x >= 10) {
        if (x % 10 == 0) {
            cout << "NO";
            return;
        }
        x /= 10;
    }
    if (x != 1)
        cout << "NO";
    else
        cout << "YES";
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
