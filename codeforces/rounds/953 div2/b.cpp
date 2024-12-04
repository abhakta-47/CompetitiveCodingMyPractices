#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll cal(ll b, ll n) {
    ll ans = b * n;
    ans -= n * (n - 1) / 2;
    return ans;
}

void sol() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (b <= a) {
        cout << n * a;
        return;
    }
    ll nb = (b - a);
    if (nb <= n) {
        cout << cal(b, nb) + a * (n - nb);
    } else {
        cout << cal(b, n);
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
