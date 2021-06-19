#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{

    int n;
    cin >> n;
    int a[2 * n + 1] = {0};
    int i, x;

    for (i = 0; i < n; i++)
    {
        cin >> x;
        ++a[x];
    }

    int s, k, ans = 0;
    for (s = 2; s <= 2 * n; s++)
    {
        k = 0;
        for (i = 1; i <= n; i++)
        {
            if (s - i > n || s - i < 0)
                continue;
            k += min(a[i], a[s - i]);
        }
        ans = max(ans, k);
    }

    cout << ans / 2;

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
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
