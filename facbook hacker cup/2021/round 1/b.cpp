#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

string imp = "Impossible\n";
string possible = "Possible\n";

ll n, m, a, b;
vector<vector<ll>> intersections;

bool valid(ll value, ll range) {
    // cout << range << " " << value << " " << range * 1000 << "\n";
    if ((range <= value) && (value <= (range * 1000)))
        return true;
    return false;
}

bool valid() { return (valid(a, n + m - 1) && valid(b, n + m - 1)); }

void sol() {
    cin >> n >> m >> a >> b;

    intersections.clear();
    intersections.resize(n, vector<ll>(m, 1000));

    if (valid()) {
        intersections[0][0] = a - (n + m - 2);
        intersections[0][m - 1] = b - (n + m - 2);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << intersections[i][j] << " ";
            cout << "\n";
        }
        return;
    }

    cout << imp;
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
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        // cout << "\n";
    }
}
