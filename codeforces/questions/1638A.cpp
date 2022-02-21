#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void special_swap(vector<ll> &a, int l, int r) {
    for (int i = l; i < (r + l + 1) / 2; i++) {
        swap(a[i], a[r - i + l]);
    }
}

void sol() {
    ll n;
    cin >> n;
    vector<ll> a;
    a.reserve(n);
    pair<ll, ll> p[n];
    loop(i, 0, n) {
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(p, p + n);
    loop(i, 0, n) {
        if (a[i] != p[i].first) {
            special_swap(a, i, a[p[i].second]);
            break;
        }
    }

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
