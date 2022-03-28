#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m, n;
    cin >> m >> n;
    char screen[m][n];
    ll energy = 0, coin = 0, maxH;
    loop(i, 0, m) { loop(j, 0, n) cin >> screen[m - i - 1][j]; }

    loop(i, 0, n) {
        maxH = 0;
        // hurdle pass
        if (screen[0][i] == 'H') {
            for (int j = 0; j < m; j++) {
                // cout << screen[j][i];
                if (screen[j][i] == '0') {
                    energy += 2 * j;
                    // cout << j << ", ";
                    break;
                }
            }
        }

        for (ll j = 0; j < m; j++)
            if (screen[j][i] == 'C') {
                ++coin;
                maxH = max(maxH, j);
            }
        energy += 2 * maxH;
    }
    cout << coin << " " << energy;
}
