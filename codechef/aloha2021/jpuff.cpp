#include <bits/stdc++.h>
using namespace std;

#define ll long long

void sol()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> v[n + 1];
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] % j == 0)
                v[j].push_back(i);

    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ", ";
        vp.push_back({v[i].size(), i});
    }
    sort(vp.begin(), vp.end());
    int ans[n + 1];
    bool taken[n];
    memset(taken, false, sizeof(taken));
    for (int i = 0; i < n; i++)
    {
        // cout << vp[i].second << "->";
        for (auto iv : v[vp[i].second])
            if (!taken[iv])
            {
                ans[vp[i].second] = a[iv] / vp[i].second;
                // cout << a[iv] / vp[i].second << " ";
                taken[iv] = true;
                break;
            }
        // cout << "\n";
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        sol();
        cout << "\n";
    }
}