#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n, k;
    // int x;
    cin >> n >> k;
    // cin >> x;
    int p;
    for (int i = 0; i < n; i++)
    {
        // cout << i << " " << x << " - ";
        if (i == 0)
            cout << 0;
        else
            cout << (i ^ (i - 1));
        // if (i != 0)
        // x ^= (i ^ (i - 1));
        cout << "\n";
        cout.flush();
        cin >> p;
        if (p == 1)
            return;
    }

    return;
}

int main()
{
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        // cout << "\n";
    }
}
