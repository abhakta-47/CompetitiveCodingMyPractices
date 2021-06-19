//http://codeforces.com/contest/1433/problems

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> ans;
    vector<int> sames;
    for (i = 1; i < n; i++)
    {
        if (a[0] != a[i])
            ans.pb({0, i});
        else
            sames.pb(i);
    }

    if (ans.size() == 0)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";

    for (i = 1; i < n; i++)
    {
        if (a[0] != a[i])
        {
            for (int j = 0; j < sames.size(); j++)
                cout << i + 1 << " " << sames[j] + 1 << "\n";
            break;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    //t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        // cout << "\n";
    }
}
