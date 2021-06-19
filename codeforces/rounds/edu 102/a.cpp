#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n, d;
    cin >> n >> d;
    int x = 101, a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout << a1 << a2;
    sort(a, a + n);
    if (a[n - 1] <= d)
        cout << "YES";
    else
    {
        if (a[1] + a[0] <= d)
            cout << "YES";
        else
            cout << "NO";
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
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
