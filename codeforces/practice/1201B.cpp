#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, i;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    ll j = n - 1, x;
    i = 0;
    ll flag = 0;
    while (i < j)
    {
        x = min(a[i], a[j]);
        a[i] -= x;
        a[j] -= x;
        if (a[i] == 0 && a[j] == 0)
        {
            if (i == j)
                flag = 1;
            ++i;
            --j;
        }
        else if (a[j] == 0)
            --j;
        else
            ++i;
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}