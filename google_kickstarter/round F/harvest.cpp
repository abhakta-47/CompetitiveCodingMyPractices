#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v;
    // v.resize(n);
    int x, y, i;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        // cout <<x<<y <<" ";
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int
        d = v[0].first,
        e, ans = 0;
    ans += ceil((v[0].second - v[0].first) * 1.0 / k);
    e = v[0].first + ceil((v[0].second - v[0].first) * 1.0 / k) * k;
    for (i = 1; i < n; i++)
    {
        // cout << v[i].first << " " << v[i].second << "     ";
        if (e > v[i].first)
        {
            v[i].first = e;
        }
        ans += ceil((v[i].second - v[i].first) * 1.0 / k);
        e = v[i].first + ceil((v[i].second - v[i].first) * 1.0 / k) * k;
    }
    cout << ans + 1;
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
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}
