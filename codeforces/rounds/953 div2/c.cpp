#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, k;

ll get_max_pos(ll x) {
    if (x % 2) {
        ll n = x / 2;
        return n * (n + 1) * 2;
    } else {
        ll n = x / 2;
        return n * n * 2;
    }
}

void sol() {
    cin >> n >> k;

    if (k % 2) {
        cout << "No";
        return;
    }
    ll max_pos_val = get_max_pos(n);
    if (k > max_pos_val) {
        cout << "No";
        return;
    }
    cout << "Yes\n";

    ll target = k / 2;
    ll start = n - 1;
    vector<ll> a(n, 0);
    loop(i, 0, n) a[i] = i + 1;
    loop(i, 0, n / 2) {
        if (target >= start) {
            target -= start;
            swap(a[i], a[n - i - 1]);
        } else
            break;
        start -= 2;
    }

    if (target == 1)
        swap(a[n / 2 - 1], a[n / 2]);
    else if (target == 2)
        swap(a[n / 2], a[n / 2 - 2]);

    loop(i, 0, n) cout << a[i] << " ";

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
