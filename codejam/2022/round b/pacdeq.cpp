#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];
    ll l = 0, r = n - 1, ans = 0, maxa = 0;
    while (l <= r) {
        if (a[l] < a[r]) {
            if (maxa <= a[l]) {
                ++ans;
                // cout << a[l] << ", ";
            }
            maxa = max(a[l], maxa);
            ++l;
        } else {
            if (maxa <= a[r]) {
                ++ans;
                // cout << a[r] << ", ";
            }
            maxa = max(a[r], maxa);
            --r;
        }
    }
    cout << ans;

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
