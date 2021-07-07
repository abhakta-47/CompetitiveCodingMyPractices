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
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] = i;
        s.insert(a[i]);
    }

    if (n == 1)
    {
        cout << 0;
        return;
    }
    if (n == 2)
    {
        if (a[0] != a[1])
            cout << 0;
        else
            cout << -1;
        return;
    }

    ll b[3] = {a[0], a[1], a[0] ^ a[1]};
    for (int i = 3; i < n; i++)
        if (i % 2)
            cout << 1 << " " << 3 << " " << i << "\n";
        else
            cout << 2 << " " << 3 << " " << i << "\n";

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
