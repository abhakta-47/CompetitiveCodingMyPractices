#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

#define MAXN 100001
vector<ll> a;
ll n, q;

ll __lcm(ll x, ll y)
{
    return x * y / __gcd(x, y);
}

ll cutCount(ll l, ll r)
{
    // cout << "in " << l << " " << r << "\n";
    ll pre[n];
    pre[l] = (ll)1;
    ll prevLCM = a[l];

    for (int i = l + 1; i <= r; i++)
    {
        // cout << "in " << l << " " << r << "\n";
        // cout << i << ": " << a[i - 1] << " " << a[i] << " gcd" << __gcd(prevLCM, a[i]) << " =";
        if (__gcd(prevLCM, a[i]) == 1)
        {
            prevLCM = __lcm(prevLCM, a[i]);
            pre[i] = pre[i - 1];
        }
        else
        {
            prevLCM = a[i];
            pre[i] = (pre[i - 1] + 1);
        }
        // cout << pre[i] << "\n";
        // cout << "in " << l << " " << r << "\n";
    }
    // cout << "in " << l << " " << r << "\n";
    // cout << "returning " << r << ": " << pre[r] << " ";
    return pre[r];
}

void sol()
{
    cin >> n >> q;
    ll i;
    a.reserve(n);
    for (i = 0; i < n; i++)
        cin >> a[i];

    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        --l;
        --r;
        cout << cutCount(l, r) << "\n";
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    //cin>>t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
