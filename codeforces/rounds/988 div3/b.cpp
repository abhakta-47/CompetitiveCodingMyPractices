#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll k;
    cin >> k;
    vector<ll> a(k);
    loop(i, 0, k) { cin >> a[i]; }

    sort(a.begin(), a.end());

    ll n = -1, m = -1;
    for (int i = 0; i < k; i++) {
        if ((k - 2) % a[i])
            continue;
        n = a[i];
        m = (k - 2) / n;
        auto it = binary_search(a.begin(), a.end(), m);
        if (it) {
            cout << n << " " << m;
            return;
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
    cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
