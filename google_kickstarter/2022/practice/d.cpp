#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

vector<vector<char>> board;
ll n, count_b, count_r, win_b, win_r;

bool col(ll col, char c) {
    for (ll i = 0; i < n; i++) {
        if (board[i][col] != c)
            return false;
    }
    return true;
}
bool row(ll r, char c) {
    for (ll i = 0; i < n; i++) {
        if (board[r][i] != c)
            return false;
    }
    return true;
}

ll count_(char c) {
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            if (board[i][j] == c)
                ++ans;
    return ans;
}
bool count_constraint() {
    count_b = count_('B');
    count_r = count_('R');
    // cout << count_b << " " << count_r << " " << (abs(count_b - count_r) <= 1)
    // << " ";
    return (abs(count_b - count_r) <= 1);
}

ll count_win_blue() {
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (row(i, 'B'))
            ++ans;
    return ans;
}
ll count_win_red() {
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (col(i, 'R'))
            ++ans;
    return ans;
}
string win_constraint() {
    if (!count_constraint())
        return "Impossible";

    win_b = count_win_blue();
    win_r = count_win_red();
    // cout << win_b << " " << win_r << " ";
    if (win_b == 1 && win_r == 0)
        return "Blue wins";
    if (win_r == 1 && win_b == 0)
        return "Red wins";
    if ((win_b + win_r) > 1)
        return "Impossible";
    return "Nobody wins";
}

void sol() {

    cin >> n;
    count_b = 0;
    count_r = 0;
    win_b = 0;
    win_r = 0;
    board.clear();
    board.resize(n, vector<char>(n));

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> board[i][j];

    cout << win_constraint();

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
