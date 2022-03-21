#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

bool isInteresting(ll x) {
    ll sum = 0, prod = 1, t = x;
    while (x) {
        sum += x % (ll)10;
        prod *= x % (ll)10;
        x /= (ll)10;
    }
    return (prod % sum == 0);
}

void sol() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for (ll i = a; i <= b; i++)
        if (isInteresting(i)) {
            ++ans;
            cout << i << ", ";
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
