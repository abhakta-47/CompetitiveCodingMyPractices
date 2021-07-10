#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xf >> yf;
    int k = 0;
    if ((xa == xb && xb == xf) && ((yf - ya) * (yf - yb) <= 0))
        k = 2;
    if ((ya == yb && yb == yf) && ((xf - xa) * (xf - xb) <= 0))
        k = 2;
    cout << abs(xa - xb) + abs(ya - yb) + k;
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
