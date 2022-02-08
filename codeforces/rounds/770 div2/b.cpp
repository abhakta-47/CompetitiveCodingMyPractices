#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

bool check(ll x, ll s, ll y) {
    // clog << x << " " << y << " " << s << " = ";
    // clog << x % 2 << y % 2 << s % 2 << "\n";
    return (((x % 2 == y % 2) && (s % 2 == 0)) ||
            ((x % 2 != y % 2) && (s % 2 != 0)));
}

void sol() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll s = 0, t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        // clog << t << ", ";
        s += t % 2;
    }
    // clog << x << " " << y << " " << s << " = ";

    if (check(x, s, y))
        cout << "Alice";
    else
        cout << "Bob";

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
