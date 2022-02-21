#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

vector<int> a;

void sol() {
    ll n;
    cin >> n;
    a.clear();
    a.resize(n);
    loop(i, 0, n) cin >> a[i];

    int l = n - 1, r, ans = 0;
    for (int substrl = 1; substrl < n; substrl *= 2) {
        r = (n > substrl ? n - substrl : n - substrl / 2);
        l = max(0, r - substrl);
        cout << l << " " << r << ", ";
        for (int i = l; i < r; i++)
            if (a[i] != a[n - 1]) {
                // cout << l << ", ";
                ++ans;
                break;
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
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
