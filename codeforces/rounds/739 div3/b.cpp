#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

bool isValid(ll x, ll n) {
    // cout << x << "?" << n << "=" << (1 <= x <= 2 * n) << ", ";
    return (1 <= x && x <= 2 * n);
}

bool isValid(ll a, ll b, ll c, ll n) {
    return (isValid(a, n) && isValid(b, n) && isValid(c, n));
}

void sol() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    // a<=b
    ll n = (b - a);
    // cout << n << " : ";
    if (isValid(a, b, c, n)) {
        if (1 <= c + n && c <= n)
            cout << c + n;
        else
            cout << c - n;
    } else
        cout << -1;
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
