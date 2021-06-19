#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll count(ll x)
{
    ll ans = 0;
    // cout << x << "->";
    while (x)
    {
        // cout << x / 10 * (10) + x % 10 << ", ";
        ans += x / 10 * (10) + x % 10;
        x /= 10;
    }
    // cout << ans << "\n";
    return ans;
}

void sol()
{
    ll l, r;
    cin >> l >> r;
    cout << count(r) - count(l);

    // cout << "\n";
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
