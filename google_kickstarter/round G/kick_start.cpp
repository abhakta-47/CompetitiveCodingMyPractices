#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    string s;
    cin >> s;
    int l = s.length();
    int counter[l][2] = {0};
    int n_kick = 0, n_start = 0;
    for (int i = 0; i < l - 3; i++)
    {
        if (s.substr(i, 4) == "KICK")
        {
            counter[i][0] = ++n_kick;
        }
    }

    for (int i = l - 5; i >= 0; i--)
    {
        if (s.substr(i, 5) == "START")
            counter[i][1] = ++n_start;
        else
            counter[i][1] = n_start;
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (counter[i][0])
            ans += counter[i][1];
    }
    cout << ans;
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
