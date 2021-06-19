#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n;
    cin >> n;
    set<int> s;
    int x, i, maxx = -1;
    bool flag = false;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        maxx = max(maxx, x);
        if (x < 0)
            flag = true;
    }

    if (flag)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n"
         << maxx + 1 << "\n";
    for (int i = 0; i <= maxx; i++)
        cout << i << " ";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
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
