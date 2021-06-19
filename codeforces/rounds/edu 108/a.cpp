#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

bool sol()
{
    ll r, b, d;
    cin >> r >> b >> d;

    //r >= b
    if (max(r, b) <= (d + (ll)1) * min(r, b))
        return true;
    else
        return false;
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
        cout << (sol() ? "YES" : "NO");
        cout << "\n";
    }
}
