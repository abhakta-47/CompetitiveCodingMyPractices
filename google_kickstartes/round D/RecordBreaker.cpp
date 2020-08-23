#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    int i, a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0, x, max_ = -1;
    for (i = 0; i < n; i++)
    {
        if (i == n - 1 && a[i] > max_)
        {
            ++ans;
            continue;
        }
        if (a[i] > max_ && a[i] > a[i + 1])
            ++ans;
        max_ = max(a[i], max_);
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
