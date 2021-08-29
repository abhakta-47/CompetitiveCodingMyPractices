#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, x;
    cin >> n;
    vector<ll> a;
    loop(i, 0, n) {
        cin >> x;
        // if (a.size() > 0 && (a[a.size() - 1] != x))
        // a.push_back(x);
        // if (a.size() == 0)
        a.push_back(x);
        // cout << a.size();
    }

    ll cur = a.size() - 1, ans = 0;
    for (int i = a.size() - 2; i >= 0; i--) {
        // cout << i << " " << cur << "=";
        if (a[i] > a[cur]) {
            ++ans;
            cur = i;
        } else if (a[i] == a[cur]) {
            cur = i;
            if (i == 0)
                ++ans;
        }
        // cout << ", ";
    }
    if (cur != 0)
        cout << -1;
    else
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
