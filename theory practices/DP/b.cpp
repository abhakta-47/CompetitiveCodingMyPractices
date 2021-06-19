//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-two-arrays/submissions/

#include <bits/stdc++.h>

using namespace std;

int sum(int *a, int r, int l)
{
    if (l == 1)
        return a[r];
    return a[r] - a[l - 2];
}

int sol()
{
    int n, q;
    cin >> n >> q;
    int a[n + 1] = {0}, b[n + 1] = {0}, i, l, r, x;
    cin >> a[1];
    for (i = 2; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 2];
    }
    cin >> b[1];
    for (i = 2; i <= n; i++)
    {
        cin >> b[i];
        b[i] += b[i - 2];
    }
    // for (i = 0; i <= n; i++)
    //     cout << a[i] << " ";
    // for (i = 0; i <= n; i++)
    //     cout << b[i] << " ";
    for (i = 1; i <= q; i++)
    {
        cin >> x >> l >> r;
        if (x == 1 && (r - l) % 2 != 0)
            cout << "0 " << sum(a, r - 1, l) << " " << sum(b, r, l + 1);

        else if (x == 1 && (r - l) % 2 == 0)
            cout << "1 " << sum(a, r, l) << " " << sum(b, r - 1, l + 1);

        else if (x == 2 && (r - l) % 2 != 0)
            cout << "2 " << sum(b, r - 1, l) << " " << sum(a, r, l + 1);

        else
            cout << "3 " << sum(b, r, l) << " " << sum(a, r - 1, l + 1);
        cout << "\n";
    }
    return 0;
}

int main()
{
    int t;
    t = 1;
    for (int i = 0; i < t; i++)
        sol();
}