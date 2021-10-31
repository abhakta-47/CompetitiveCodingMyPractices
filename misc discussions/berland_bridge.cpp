#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> teams;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        teams[x].push_back(y);
    }

    int dp[n + 1];
    memset(dp, INT_MAX, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
