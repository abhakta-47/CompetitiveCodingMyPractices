#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    int x, y;
    cin >> y;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        // cout << y << " "
            //  << x << " "
            //  << (log2((max(x, y) * 1.0 / min(x, y)))) << " "
            //  << ceil(log2((max(x, y) * 1.0 / min(x, y)))) - 1 << "\n";

        ans += ceil(log2((max(x, y) * 1.0 / min(x, y)))) - 1;
        y = x;
    }
    cout << ans;
    // cout << " ****************";
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
