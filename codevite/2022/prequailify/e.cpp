#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

char board[3][3];
int xCount = 0, oCount = 0;
int xWin = 0, oWin = 0;
bool countBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X')
                xCount++;
            if (board[i][j] == 'O')
                oCount++;
        }
    }
    return (xCount == oCount || (xCount == (oCount + 1)));
}

bool isWinner(char c) {
    int ans = 0;
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][2] == board[i][1] &&
            board[i][0] == c)
            ++ans;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[2][i] == board[1][i] &&
            board[0][i] == c)
            ++ans;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[2][2] == c)
        ++ans;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        board[2][0] == c)
        ++ans;
    return ans;
}

bool winCond() {
    xWin = isWinner('X');
    oWin = isWinner('O');

    // if (xWin + oWin > 1)
    //     return false;

    if (oWin >= 1) {
        if (xWin >= 1)
            return false;
        return (xCount == oCount);
    }

    if (xWin >= 1 && (xCount != (oCount + 1)))
        return false;

    return true;
}

bool sol() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];
    // for (int i = 0; i < 3; i++)
    //     for (int j = 0; j < 3; j++)
    //         cout << board[i][j];

    if (!countBoard())
        return false;

    return winCond();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        cout << (sol() ? "YES" : "NO");
        // clog<<"\n";
        // cout << "\n";
    }
}
