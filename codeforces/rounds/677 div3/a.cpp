//http://codeforces.com/contest/1433/problems
// done :)
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int x;
    cin >> x;
    int l = 4; // 9 999 < 10 000   10
    int y = x, n_digit = 0;
    while (x > 0)
    {
        x /= 10;
        ++n_digit;
    }

    // cout << 10 * (y % 10 - 1) << " " << n_digit * (n_digit + 1) / 2;
    cout << 10 * (y % 10 - 1) + n_digit * (n_digit + 1) / 2;

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
