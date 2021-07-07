#include <bits/stdc++.h>

using namespace std;

#define ll long long

void sol()
{

    int n;
    cin >> n;
    int a[2 * n];
    int n_even = 0, n_odd = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            ++n_odd;
        else
            ++n_even;
    }

    if (n_even == n_odd)
        cout << "YES";
    else
        cout << "NO";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    cin >> t;
    while (t--)
    {
        // clog << "test case #"<<t<<":\n";
        sol();
        cout << "\n";
        // clog<<"\n";
    }
}
