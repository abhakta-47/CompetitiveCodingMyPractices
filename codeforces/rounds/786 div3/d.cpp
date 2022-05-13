#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    loop(i, 0, n) {
        cin >> a[i];
        b[i] = a[i];
    };
    sort(b, b + n);

    ll s = 0;
    if (n % 2) {
        if (a[0] == b[0])
            s = 1;
        else {
            cout << "NO";
            return;
        }
    }

    for (int i = s; i < n; i += 2) {

        if (a[i] == b[i] && a[i + 1] == b[i + 1])
            continue;

        if (a[i] == b[i + 1] && a[i + 1] == b[i])
            continue;

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
