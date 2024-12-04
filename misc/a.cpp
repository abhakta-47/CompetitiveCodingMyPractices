#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll min_adjacent(vector<vector<ll>> &a, ll x, ll y) {
    ll n = a.size();
    ll m = a[0].size();
    ll ans = LONG_LONG_MAX;
    if (x != 0)
        ans = min(ans, a[x - 1][y]);
    if (x != n - 1)
        ans = min(ans, a[x + 1][y]);
    if (y != 0)
        ans = min(ans, a[x][y - 1]);
    if (y != m - 1)
        ans = min(ans, a[x][y + 1]);

    return ans;
}

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    loop(i, 0, n) loop(j, 0, m) cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = min_adjacent(a, i, j);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
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
