#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll s = 0, maxA = 0, x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s += x;
        if (i == 0)
            maxA = x;
        else
            maxA = max(maxA, x);
    }

    s -= maxA;
    cout << fixed << setprecision(6);
    cout << s * 1.0 / (n - 1) + maxA * 1.0;

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
