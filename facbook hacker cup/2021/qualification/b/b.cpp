#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

vector<vector<char>> table;
vector<ll> m;
ll n;
void countRow(ll x) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (table[x][i] == 'O')
            return;
        else if (table[x][i] == '.')
            ++cnt;
    }
    // cout << m[1][cnt];
    m[cnt]++;
    // cout << "row " << x << "->" << cnt << "=" << m[cnt] << ", ";
}

ll getXs(ll x) {
    ll cnt = 0;
    for (int i = 0; i < n; i++)
        if (table[x][i] == 'O')
            return -1;
        else if (table[x][i] == '.')
            ++cnt;
    if (cnt == 1) {
        for (int i = 0; i < n; i++)
            if (table[x][i] == '.')
                return i;
    }
    return -1;
}

void countCol(ll x) {
    ll cnt = 0, pos = -1;
    for (int i = 0; i < n; i++)
        if (table[i][x] == 'O')
            return;
        else if (table[i][x] == '.') {
            ++cnt;
            pos = i;
        }
    if (cnt == 1 && getXs(pos) != -1 && table[getXs(pos)][x] == '.')
        return;

    m[cnt]++;
    // cout << "col " << x << "->" << cnt << "=" << m[cnt] << ", ";
}

void __count(int x) {
    // if (r == 1)
    countRow(x);
    // else
    countCol(x);
}

void sol() {
    cin >> n;
    table.clear();
    table.resize(n, vector<char>(n));
    loop(i, 0, n) loop(j, 0, n) cin >> table[i][j];
    m.clear();
    m.resize(n + 1, 0);
    loop(i, 0, n) __count(i);

    // cout << "\n";
    // loop(i, 0, n + 1) cout << i << " " << m[i] << ", ";
    // cout << "\n";

    // ll ans = n + 1;
    loop(i, 0, n + 1) {
        if (m[i] != 0) {
            cout << i << " " << m[i];
            return;
        }
    }

    cout << "Impossible";

    return;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
