#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    loop(i, 1, n + 1) cin >> a[i];

    loop(i, 1, n + 1) {
        if (a[i] == i)
            continue;
        if (a[i] == i + 1 && a[i + 1] == i) {
            ++i;
            continue;
        }

        cout << "NO";
        return;
    }

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
