#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, 0, n) cin >> a[i];
    ll ans = 0, x = 0;
    loop(i, 0, n) {
        x = 1;
        loop(j, 0, i) {
            if (a[j] <= a[i])
                ++x;
        }
        ans = max(ans, x);
    }

    cout << n - ans;

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
