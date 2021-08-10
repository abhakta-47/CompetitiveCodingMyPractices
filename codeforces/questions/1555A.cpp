#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    if (n <= 6)
        cout << 15;
    else if (n % 2)
        cout << (n + 1) / 2 * 5;
    else
        cout << n / 2 * 5;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;

    t = 1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
