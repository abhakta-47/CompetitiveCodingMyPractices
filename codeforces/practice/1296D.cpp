#include <bits/stdc++.h>

using namespace std;

#define ll float

int func()
{
    int a, b, k, p = 0;
    int n, i;
    cin >> n >> a >> b >> k;
    int h[n];
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
        h[i] = (h[i] % (a + b));
        if (0 < h[i] && h[i] <= a)
            h[i] = 0;
        else
        {
            h[i] = (h[i] == 0) ? a + b : h[i];
            h[i] = (ceil(h[i] * 1.0 / a * 1.0)) - 1;
        }
    }

    sort(h, h + n);

    for (i = 0; i < n; i++)
    {
        if (h[i] == 0)
            ++p;
        else if (h[i] <= k)
        {
            ++p;
            k -= h[i];
        }
    }

    cout << p;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    t = 1; //cin>>t;
    //cout << (5 * 1.0 / 2 * 1.0) << "    ";
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}