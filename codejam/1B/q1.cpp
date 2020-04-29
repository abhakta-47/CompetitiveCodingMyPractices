#include <bits/stdc++.h>

using namespace std;

//#define int long long
int k;
vector<pair<int, int> > ans;

void block(int x)
{
    vector<int> v;

    while (x > 0)
    {
        v.push_back(x % 2);
        x = x / 2;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            ans.push_back(make_pair(i, k));
        }
    }
}

int func()
{
    int x, y;
    cin >> x >> y;
    if ((x + y) % 2 == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    if (y % 2)
    {
        if (y > 0)
            --y;
        else
            ++y;
        ans.push_back(make_pair(0, 1));
    }
    else
    {
        if (x > 0)
            --x;
        else
            ++x;
        ans.push_back(make_pair(0, 0));
    }

    if (((x & y) | ((~x) & (~y))) != 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    k = 0;
    block(x);
    k = 1;
    block(y);
    sort(ans.begin(), ans.end());
    int i;
    for (i = 0; i < ans.size(); i++)
    {
        if (ans[i].second == 0)
        {
            if (x < 0)
                cout << 'W';
            else
                cout << 'E';
        }
        else
        {
            if (y < 0)
                cout << 'S';
            else
                cout << 'N';
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}