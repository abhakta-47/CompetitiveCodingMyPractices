#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

long long func()
{
    long long n;
    cin >> n;

    long long i, j, x, r, c, count[2 * n] = {0}, ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> x;
            r = i;
            c = j;
            if (r > c)
            {
                r = r - c;
                c = 0;
                count[n + r] += x;
                // cout << n + r << "-" << count[n + r] << " ";
            }
            else
            {
                c = c - r;
                r = 0;
                count[c] += x;
                // cout << count[c] << " ";
            }
        }
    }
    for (i = 0; i < 2 * n; i++)
        if (count[i] > ans)
            ans = count[i];
    cout << ans;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, i;
    //t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}
