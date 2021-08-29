#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ++m[a[i]];
    }
    int ans = 0;
    for (auto im : m)
        ans += (im.second * im.second);
    cout << n * n - ans;
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
