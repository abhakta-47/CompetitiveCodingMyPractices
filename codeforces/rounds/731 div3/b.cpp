#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    string s;
    cin >> s;
    vector<pair<char, int>> m;
    int l, r;
    for (int i = 0; i < s.length(); i++)
        m.push_back({s[i], i});
    // m[s[i]] = i;
    sort(m.begin(), m.end());
    int k = 0, curp;
    for (auto im : m)
    {
        // cout << im.second << " ";
        if (im.first != (int('a') + k))
        {
            // cout << im.first;
            cout << "NO";
            return;
        }
        ++k;
        curp = im.second;
        if (im.first == 'a')
        {
            l = curp;
            r = curp;
            continue;
        }
        if (curp - r == 1)
            r = curp;
        else if (l - curp == 1)
            l = curp;
        else
        {
            cout << "NO";
            return;
        }
        // cout << im.first;
    }
    cout << "YES";
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
