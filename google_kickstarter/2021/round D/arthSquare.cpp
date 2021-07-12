#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

inline bool check(ll a[3])
{
    return (((a[0] + a[2]) == ((ll)2 * a[1])) ? true : false);
}
inline bool check(ll x, ll y, ll z)
{
    ll a[3] = {x, y, z};
    sort(a, a + 3);
    return (((a[0] + a[2]) == (2 * a[1])) ? true : false);
    // return (((x + z) == (2 * y)) ? (true) : false);
}

void sol()
{
    ll g[3][3];
    for (ll i = 0; i < 3; i++)
        cin >> g[0][i];
    cin >> g[1][0] >> g[1][2];
    for (ll i = 0; i < 3; i++)
        cin >> g[2][i];

    ll ans = 0;
    if (check(g[0][0], g[0][1], g[0][2]))
        ++ans;
    if (check(g[2][0], g[2][1], g[2][2]))
        ++ans;
    if (check(g[0][0], g[1][0], g[2][0]))
        ++ans;
    if (check(g[0][2], g[1][2], g[2][2]))
        ++ans;
    // map<ll, ll> m;
    ll d, maxa = 0, cura;
    if ((g[0][0] + g[2][2]) % (ll)2 == 0)
    {
        // ++m[(g[0][0] + g[2][2]) / (ll)2];
        cura = 0;
        d = (g[0][0] + g[2][2]) / (ll)2;

        if (check(g[0][0], d, g[2][2]))
            ++cura;
        if (check(g[0][2], d, g[2][0]))
            ++cura;
        if (check(g[0][1], d, g[2][1]))
            ++cura;
        if (check(g[1][0], d, g[1][2]))
            ++cura;
        maxa = max(maxa, cura);
    }

    if ((g[0][2] + g[2][0]) % (ll)2 == 0)
    {
        // ++m[(g[0][2] + g[2][0]) / (ll)2];
        cura = 0;
        d = (g[0][2] + g[2][0]) / (ll)2;
        if (check(g[0][0], d, g[2][2]))
            ++cura;
        if (check(g[0][2], d, g[2][0]))
            ++cura;
        if (check(g[0][1], d, g[2][1]))
            ++cura;
        if (check(g[1][0], d, g[1][2]))
            ++cura;
        maxa = max(maxa, cura);
    }

    if ((g[0][1] + g[2][1]) % (ll)2 == 0)
    {
        // ++m[(g[0][1] + g[2][1]) / (ll)2];
        cura = 0;
        d = (g[0][1] + g[2][1]) / (ll)2;
        if (check(g[0][0], d, g[2][2]))
            ++cura;
        if (check(g[0][2], d, g[2][0]))
            ++cura;
        if (check(g[0][1], d, g[2][1]))
            ++cura;
        if (check(g[1][0], d, g[1][2]))
            ++cura;
        maxa = max(maxa, cura);
    }

    if ((g[1][0] + g[1][2]) % (ll)2 == 0)
    {
        // ++m[(g[1][0] + g[1][2]) / (ll)2];
        cura = 0;
        d = (g[1][0] + g[1][2]) / (ll)2;
        if (check(g[0][0], d, g[2][2]))
            ++cura;
        if (check(g[0][2], d, g[2][0]))
            ++cura;
        if (check(g[0][1], d, g[2][1]))
            ++cura;
        if (check(g[1][0], d, g[1][2]))
            ++cura;
        maxa = max(maxa, cura);
    }

    // ll maxa = m.begin()->second;
    // for (auto im : m)
    // {
    //     // cout << im.first << "->" << im.second << ", ";
    //     maxa = max(maxa, im.second);
    // }
    cout << ans + maxa;

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
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        sol();
        cout << "\n";
    }
}
