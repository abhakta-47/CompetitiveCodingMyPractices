//http://codeforces.com/contest/1433/problems
// :)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    int i, a[n], max_a = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        // cout << a[i] << " " << max_a << "  ";
        max_a = max(a[i], max_a);
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] == max_a && a[i] > a[i + 1])
            {
                cout << i + 1;
                return 0;
            }
            continue;
        }

        if (i == n - 1)
        {
            if (a[i] == max_a && a[i - 1] < a[i])
            {
                cout << i + 1;
                return 0;
            }
            continue;
        }

        if (a[i] == max_a && (a[i - 1] < a[i] || a[i] > a[i + 1]))
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << "-1";
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
