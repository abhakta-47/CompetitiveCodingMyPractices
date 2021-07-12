#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> problemset;
    ll students[m], x, y, s;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        problemset.push_back({x, y});
    }
    for (int i = 0; i < m; i++)
        cin >> students[i];

    sort(problemset.begin(), problemset.end());
    ll ans[m] = {0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < problemset.size(); j++)
        {
            x = problemset[j].first;
            y = problemset[j].second;
            s = students[i];
            if (x == s && s == y)
            {
                problemset.erase(problemset.begin() + j);
                ans[i] = s;
                break;
            }
            else if (x == s)
            {
                problemset[j].first = x + 1;
                ans[i] = s;
                break;
            }
            else if (y == s)
            {
                problemset[j].second = y - 1;
                ans[i] = s;
                break;
            }
            else if ((x < s) && (s < y))
            {
                ans[i] = s;
                problemset[j].second = s - 1;
                problemset.push_back({s + 1, y});
                sort(problemset.begin(), problemset.end());
                break;
            }
            else if ((s < x))
            {
                if (j == 0)
                {
                    ans[i] = x;
                    if (x == y)
                        problemset.erase(problemset.begin() + j);
                    else
                        problemset[j].first = problemset[j].first + 1;
                }
                else
                {
                    ll x1 = problemset[j - 1].first, y1 = problemset[j - 1].second;
                    if ((s - y1) <= (x - s))
                    {
                        ans[i] = y1;
                        if (x1 != y1)
                            problemset[j - 1].second = y1 - 1;
                        else
                            problemset.erase(problemset.begin() + j - 1);
                    }
                    else
                    {
                        ans[i] = x;
                        if (x == y)
                            problemset.erase(problemset.begin() + j);
                        else
                            problemset[j].first = x + 1;
                    }
                }
                break;
            }
        }
    }
    for (auto is : ans)
        cout << is << " ";
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
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        sol();
        cout << "\n";
    }
}
