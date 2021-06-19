#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    vector<string> m[26];
    int i, j;
    string s;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        m[int(s[0]) - 97].pb(s.substr(1, (s.length() - 1)));
    }

    for (i = 0; i < n; i++)
    {
        sort(m[0].begin(), m[0].end());
    }

    // for (i = 0; i < 26; i++)
    // {
    //     //cout << char(i + 97) << "-> ";
    //     for (auto is : m[i])
    //         //cout << is << " ";

    //     //cout << "\n";
    // }
    ll ans = 0;
    for (i = 0; i < 26; i++)
    {
        if (m[i].size() == 0)
            continue;
        //cout << char(i + 97) << "-> ";
        // for (auto is : m[i])
        //cout << is << " ";
        //cout << "\n";

        for (j = 0; j < 26; j++)
        {
            if (i == j)
                continue;
            if (m[j].size() == 0)
                continue;

            //cout << "    " << char(j + 97) << "-> ";
            // for (auto is : m[j])
            //cout << is << " ";

            vector<string> sc(min(m[i].size(), m[j].size()));
            int nce = set_intersection(m[i].begin(), m[i].end(),
                                       m[j].begin(), m[j].end(),
                                       sc.begin()) -
                      sc.begin();

            ans += (m[i].size() - nce) * (m[j].size() - nce);
            //cout << "     " << nce << "\n";
        }
        //cout << "\n";
    }

    cout << ans;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    // t = 1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout << "Case #" << i + 1 << ": \n";
        func();
        cout << "\n";
    }
}
