#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    string q;
    ll p = 0, x;
    loop(i, 0, n) {
        cin >> q >> x;
        if (q == "P")
            p += x;
        else {
            if (x <= p)
                cout << "NO";
            else
                cout << "YES";
            cout << "\n";
            p -= x;
            p = max(p, 0ll);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
