#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int prevl, prevr = -1, l, r;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            l = (0 <= i - m ? i - m : 0);
            r = (i + m < n ? i + m : n - 1);
            cout << l << "-" << r << " ";
            if (prevr < l)
                v.push_back({l, r});
            else
                v[v.size() - 1].second = r;
            prevr = r;
        }
    }
    cout << "\n";

    for (auto iv : v)
        for (int i = iv.first; i <= iv.second; i++)
        {
            // cout << iv.first << "-" << iv.second << " ";
            s[i] = '1';
        }
    // cout << " ";
    cout << s;

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
