#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void brute(ll n) {
    ll edges = 0, t, initnode;
    cin >> initnode >> edges;
    loop(i, 0, n) {
        if ((i + 1) == initnode)
            continue;
        cout << "T " << i + 1 << "\n";
        cin >> t >> t;
        edges += t;
    }
    cout << "E " << edges / 2 << "\n";
}

void sol() {
    ll n, k;
    cin >> n >> k;
    if (n <= k) {
        brute(n);
        return;
    }

    return;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // cout << "Case #" << i + 1 << ": ";
        sol();
        // cout << "\n";
    }
}
