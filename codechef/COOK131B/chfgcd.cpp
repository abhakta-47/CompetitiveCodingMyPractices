#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll x, y;
    cin >> x >> y;
    ll gcdXY = __gcd(x, y);
    if (gcdXY != 1)
        cout << 0;
    else if (__gcd(x + 1, y) != 1 || __gcd(x, y + 1) != 1)
        cout << 1;
    else
        cout << 2;

    return;
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
        sol();
        cout << "\n";
    }
}
