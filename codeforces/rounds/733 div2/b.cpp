#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int h, w;
bool ans[4][21] = {0};

bool check(int x, int y)
{
    if (!(x == 1 || y == 1 || x == h || y == w))
        return false;

    if (ans[x - 1][y] || ans[x][y - 1] ||
        ans[x + 1][y] || ans[x][y + 1] ||
        ans[x - 1][y - 1] || ans[x - 1][y + 1] ||
        ans[x + 1][y + 1] || ans[x + 1][y - 1])
        return false;

    return true;
}

void sol()
{
    cin >> h >> w;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (check(i, j))
                ans[i][j] = 1;
            else
                ans[i][j] = 0;
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return;
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
        sol();
        cout << "\n";
    }
}
