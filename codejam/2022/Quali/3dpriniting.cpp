#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll TOTAL_COLOR = 1000000;

void sol() {
    ll colors[3][4];
    loop(i, 0, 3) cin >> colors[i][0] >> colors[i][1] >> colors[i][2] >>
        colors[i][3];
    ll print_colors[4] = {TOTAL_COLOR, TOTAL_COLOR, TOTAL_COLOR, TOTAL_COLOR},
       sum = 0;
    loop(i, 0, 4) {
        loop(j, 0, 3) { print_colors[i] = min(colors[j][i], print_colors[i]); }
        sum += print_colors[i];
    }
    if (sum < TOTAL_COLOR) {
        cout << "IMPOSSIBLE";
        return;
    }
    sum -= TOTAL_COLOR;
    ll t;
    loop(i, 0, 4) {
        t = min(print_colors[i], sum);
        print_colors[i] -= t;
        sum -= t;
    }
    loop(i, 0, 4) cout << print_colors[i] << " ";
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
        cout << "\n";
    }
}
