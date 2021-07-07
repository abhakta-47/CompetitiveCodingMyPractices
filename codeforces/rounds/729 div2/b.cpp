#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool sol()
{

    ll n, a, b;
    cin >> n >> a >> b;

    if (a == 1 && (n - 1) % b != 0)
        return 0;

    if (b == 1)
        return 1;

    ll x = 1;
    while (n >= x)
    {
        if ((n - x) % b == 0)
            return 1;
        x *= a;
    }

    return 0;
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
        cout << (sol() ? "YES" : "NO");
        cout << "\n";
        // clog<<"\n";
    }
}
