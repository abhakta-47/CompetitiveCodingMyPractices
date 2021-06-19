#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // clog << a[i]<<"";
    }
    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i - 1][j - 1] + a[i - 1] << "," << dp[i - 1][j];
            dp[i][j] = max(dp[i - 1][j - 1] + a[i - 1], dp[i - 1][j]);
            cout << "=" << dp[i][j] << "\t";
        }

        cout << "\n";
    }
    cout << "\n";

    int ans = 0;
    for (int j = 0; j <= n; j++)
    {
        if (dp[n][j] > dp[n][ans])
            ans = j;
    }
    cout << ans;

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
