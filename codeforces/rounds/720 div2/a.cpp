#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll a, b;
    cin >> a >> b;
    if (b == 1)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    if (b == 2)
    {
        cout << a << " " << a * 3 << " " << a * 2 * 2;
        return;
    }
    cout << a << " " << a * (b - 1) << " " << a * b;
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
