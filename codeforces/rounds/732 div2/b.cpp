#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, m;
    cin >> n >> m;
    string s1[n], s2[n];
    for (int i = 0; i < n; i++)
        cin >> s1[i];
    for (int i = 0; i < n - 1; i++)
        cin >> s2[i];
    ll values[2][m];
    memset(values, 0, sizeof(values));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            values[0][j] += (ll)s1[i][j];
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            values[1][j] += (ll)s2[i][j];
    for (int i = 0; i < m; i++)
    {
        // cout << values[0][i] << " " << values[1][i] << "\t";
        cout << char(values[0][i] - values[1][i]);
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
