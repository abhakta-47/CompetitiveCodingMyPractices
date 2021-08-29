#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

void sol() {
    ll n;
    cin >> n;
    ll x = pow(n, .5);
    if (x * x < n)
        x++;
    // cout << x << " ";
    ll c = min(x * x - n + 1, x);
    ll r = x;
    if (c == x)
        r = n - (x - 1) * (x - 1);
    cout << r << " " << c;
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
