#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{

    int n;
    cin >> n;
    int a[n - 1], i, x, y;
    cin >> y;
    for (i = 0; i < n - 1; i++)
    {
        cin >> x;
        a[i] = x - y;
        y = x;
    }
    int k = 2, ans = 0;
    
    for (i = 1; i < n - 1; i++)
    {
        // cout << a[i];
        if (a[i] == a[i - 1])
            ++k;
        else
        {
            ans = max(ans, k);
            k = 2;
        }
        // cout << "="<<k <<" ";
    }
    ans=max(ans,k);
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
