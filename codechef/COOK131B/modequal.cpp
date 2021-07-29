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
        m[a[i]]++;
    }
    if (m.size() == 1)
    {
        cout << 0;
        return;
    }
    ll minEl = m.begin()->first, sndEl = (++m.begin())->first;
    if (2 * minEl < sndEl)
        cout << n - m.begin()->second;
    else
        cout << n;
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
