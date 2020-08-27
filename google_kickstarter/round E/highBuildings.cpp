#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if (n == 1)
    {
        if (a == 1 && b == 1 && c == 1)
            cout << 1;
        else
            cout << "IMPOSSIBLE";
    }
    else if (n == 2)
    {
        if (a == 2 && b == 2 && c == 2)
            cout << "1 1";
        else if (a == 2 && b == 1 && c == 1)
            cout << "1 2";
        else if (a == 1 && b == 2 && c == 1)
            cout << "2 1";
        else
            cout << "IMPOSSIBLE";
    }
    else
    {
        if ((a + b - c > n) || (a == c && b == c && c == 1))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        int i;
        vector<int> ans, ans_start, ans_mid, ans_end;

        for (i = 1; i <= (a - c); i++)
            ans_start.pb(2);
        for (i = 1; i <= (b - c); i++)
            ans_end.pb(2);

        if (a == c && b != c)
            ans_mid.pb(3);

        for (i = 1; i < c; i++)
            ans_mid.pb(3);
        for (i = 1; i <= (n - a - b + c); i++)
            ans_mid.pb(1);

        if (!(a == c && b != c))
            ans_mid.pb(3);

        for (i = 0; i < ans_start.size(); i++)
            cout << ans_start[i] << " ";

        for (i = 0; i < ans_mid.size(); i++)
            cout << ans_mid[i] << " ";

        for (i = 0; i < ans_end.size(); i++)
            cout << ans_end[i] << " ";
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
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}
