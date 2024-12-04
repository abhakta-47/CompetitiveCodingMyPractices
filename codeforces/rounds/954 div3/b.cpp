#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, m;

bool is_valid(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < m; }

void update_value(vector<vector<ll>> &a, ll x, ll y) {
    if (!is_valid(x, y))
        return;

    vector<ll> neighbours;
    if (is_valid(x - 1, y)) {
        neighbours.pb(a[x - 1][y]);
    }
    if (is_valid(x + 1, y)) {
        neighbours.pb(a[x + 1][y]);
    }
    if (is_valid(x, y - 1)) {
        neighbours.pb(a[x][y - 1]);
    }
    if (is_valid(x, y + 1)) {
        neighbours.pb(a[x][y + 1]);
    }
    sort(neighbours.begin(), neighbours.end());
    a[x][y] = min(a[x][y], neighbours[neighbours.size() - 1]);
}

void sol() {
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    loop(i, 0, n) loop(j, 0, m) cin >> a[i][j];
    // loop(i, 0, n) {
    //     loop(j, 0, m) { cout << a[i][j] << " "; }
    //     cout << "\n";
    // }

    // cout << "\n\n";
    vector<vector<ll>> poss(n * m, vector<ll>(3));
    loop(i, 0, n) loop(j, 0, m) {
        poss[i * m + j][0] = a[i][j];
        poss[i * m + j][1] = i;
        poss[i * m + j][2] = j;
    }

    sort(poss.begin(), poss.end());

    loop(i, 0, n * m) {
        // cout << poss[i][0] << " " << poss[i][1] << " " << poss[i][2] << "\n";
        ll x, y;
        x = poss[i][1];
        y = poss[i][2];

        update_value(a, x - 1, y);
        update_value(a, x + 1, y);
        update_value(a, x, y - 1);
        update_value(a, x, y + 1);
    }

    loop(i, 0, n) {
        loop(j, 0, m) { cout << a[i][j] << " "; }
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
        // cout << "\n";
    }
}
