#include <bits/stdc++.h>

using namespace std;

long long func()
{
    long long n;
    cin >> n;
    long long a[2][n], i, min_a = 2147483647, min_b = 2147483647;
    for (i = 0; i < n; i++)
    {
        cin >> a[0][i];
        min_a = min(min_a, a[0][i]);
    }
    for (i = 0; i < n; i++)
    {
        cin >> a[1][i];
        min_b = min(min_b, a[1][i]);
    }
    long ans = 0;
    // cout << min_a << " " << min_b << "\n";
    for (i = 0; i < n; i++)
    {
        // cout << "   " << max(a[0][i] - min_a, a[1][i] - min_b) << "\n";
        ans += max(a[0][i] - min_a, a[1][i] - min_b);
        // cout << "  " << ans << " ";
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
        cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
