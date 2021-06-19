#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    int d[2 * n + 1], a[n + 1], s = 0;
    bool flag = true;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> d[i];
        if (d[i] % 2)
            flag = false;
        d[i] /= 2;
    }
    if (flag == false)
    {
        cout << "NO";
        return 0;
    }
    // cout << " #1# ";
    if (n == 1 && (d[1] != d[2] || (d[1] == d[2] && (d[1] + d[2]) != 0)))
    {
        cout << "NO";
        return 0;
    }
    // cout << " #2# ";
    // sort(d + 1, d + 2 * n + 1);
    for (int i = n; i >= 1; i -= 1)
    {
        // cout << d[2 * i] << " = " << d[2 * i - 1] << "\t";
        if (d[2 * i] != d[2 * i - 1])
        {
            cout << "NO";
            return 0;
        }
        // cout << d[2 * i] << "-" << s << "/" << i << "=";
        if ((d[2 * i] - s) % i)
        {
            cout << "NO";
            return 0;
        }

        a[i] = (d[2 * i] - s) / i;
        // cout << a[i] << " ";
        s += a[i];
    }
    // cout << " #3# ";
    for (int i = 1; i < n; i++)
    {
        // cout << a[i] << " <= " << a[i + 1] << "\t";
        if (a[i] > a[i + 1] || a[i]==0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
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
