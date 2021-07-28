#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
// 1 2 3 4 5 6 7 8 9 10 11 12
// 2 3 2 3 2 4 2 3 2  3  2  5

void sol()
{
    ll n;
    cin >> n;
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << "=";
        x = 1;
        while (i % x == 0)
            ++x;
        cout << x << " ";
        if (i % 12 == 0)
            cout << "\n";
    }

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
