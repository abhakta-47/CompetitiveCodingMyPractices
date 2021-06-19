#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int sol()
{
    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];

    // 0
    for (i = 0; i < n; i++)
        if (a[i] != (i + 1))
            break;
    if (i == n)
        return 0;

    // 3
    if (a[0] == n && a[n - 1] == 1)
        return 3;

    if (a[0] == 1 || a[n - 1] == n)
        return 1;

    return 2;
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
        cout << sol();
        cout << "\n";
    }
}
