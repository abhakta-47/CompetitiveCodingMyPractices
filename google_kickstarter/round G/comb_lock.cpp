#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

long long diff(long long x, long long y, long long n)
{
    if (x < y)
    {
        x = x + y;
        y = x - y; // x+y-y=x
        x = x - y; //  x+y-x=y
    }

    return min((x - y), (n - x + y));
}

long long func()
{
    long long w, n, i;
    cin >> w >> n;
    long long init[w];
    for (i = 0; i < w; i++)
        cin >> init[i];
    unsigned long long t = 0, ans = ULLONG_MAX;
    for (i = 0; i < w; i++)
    {
        t = 0;
        for (long long j = 0; j < w; j++)
        {
            // cout << i << "," << j << " - " << diff(init[i], init[j], n) << "    ";
            t += diff(init[i], init[j], n);
        }
        ans = min(ans, t);
        // cout << t << " = " << ans << "\n";
    }
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
