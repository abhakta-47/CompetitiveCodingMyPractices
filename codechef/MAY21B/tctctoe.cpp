#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

char board[3][3];
int nX, nO, nS;

void counter()
{
    int i, j;
    nX = 0;
    nO = 0;
    nS = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            switch (board[i][j])
            {
            case 'X':
                ++nX;
                break;
            case 'O':
                ++nO;
                break;
            case '_':
                ++nS;
                break;
            default:
                break;
            }
}

bool win(char c)
{
    int i;
    for (i = 0; i < 3; i++)
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return true;

    for (i = 0; i < 3; i++)
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return true;

    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;

    if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;

    return false;
}

int sol()
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> board[i][j];

    counter();
    // cout << nX << " " << nO << " " << nS << " ";

    //return 1
    //draw :    no space & no win & valid
    if (nS == 0 && !win('X') && !win('O') && (nX == nO || nX - nO == 1))
        return 1;
    //X win:    only x win & nx-no=1
    if (win('X') && !win('O') && nX - nO == 1)
        return 1;
    //O win: only y win & nx==no
    if (win('O') && !win('X') && nX == nO)
        return 1;
    //return 2: sapce & no win & valid
    if (nS > 0 && !win('X') && !win('O') && (nX == nO || nX - nO == 1))
        return 2;

    //else
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        cout << sol();
        cout << "\n";
    }
}
