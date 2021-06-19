#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
ll n;
ll traverse(ll *a, ll i, ll s)
{
    if (!(i < n))
        return 0;

    if (a[i] >= 0)
    {
        int k1 = 1 + traverse(a, i + 1, s + a[i]);
        clog << i << "-" << s << "-" << k1 << ", ";
        return k1;
    }

    if (a[i] + s >= 0)
    {
        int k1 = max(
            traverse(a, i + 1, s),
            (1 + traverse(a, i + 1, s + a[i])));
        clog << i << "-" << s << "-" << k1 << ", ";
        return k1;
    }
    else // a[i]+s<0
    {
        int k1 = traverse(a, i + 1, s);
        clog << i << "-" << s << "-" << k1 << ", ";
        return k1;
    }
}

void sol()
{
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << traverse(a, 0, 0);

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
        clog << "Case #" << t << ": ";
        sol();
        cout << "\n";
        clog << "\n";
    }
}
