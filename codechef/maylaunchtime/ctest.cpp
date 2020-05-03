#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> v, bl, br;
ll l_l, l_r, l_f, x, y, l, r, p;

vector<ll> decToBinary(ll n)
{

    vector<ll> t;
    t.clear();
    int i = 0;
    if (n == 0)
        t.push_back(0);
    while (n > 0)
    {
        t.push_back(n % 2);
        n = n / 2;
        i++;
    }
    return t;
}

ll func4(ll t)
{
    return (x & t) * (y & t);
}

ll func2(ll n, bool sr, bool gl)
{

    ll t, bit_l, bit_r, bit_f, ans = 0, i;
    p = n - 1;
    bool flag = true;

    for (i = n - 1; i >= 0; i--)
    {

        bit_l = (i >= l_l) ? 0 : bl[i];
        bit_f = (i >= l_f) ? 0 : v[i];
        bit_r = (i >= l_r) ? 0 : br[i];

        // sg smaller than greater && gs greater than smaller

        if (bit_r == 1)
            t = bit_f;
        else
        {
            if (sr)
                t = bit_f;
            else
                t = 0;
        }

        if (t < bit_r)
            sr = true;

        if (bit_r == 1 && bit_f == 1 && flag)
        {
            p = i;
            flag = false;
        }

        ans += t * pow(2, i);
    }

    if (func4(ans) == 0)
        ans = l;

    return ans;
}
ll max2(ll t1, ll t2)
{
    ll ans;
    if (func4(t1) > func4(t2))
        ans = t1;
    else if (func4(t2) > func4(t1))
        ans = t2;
    else
        ans = min(t1, t2);
    return ans;
}
int func()
{
    l = 0;
    //cin >> x >> y >> l >> r;

    bl = decToBinary(l);
    br = decToBinary(r);
    v = decToBinary(x | y);
    l_l = bl.size();
    l_r = br.size();
    l_f = v.size();

    ll sum = 0;
    ll i;

    sum = func2(l_r, false, true);
    ll ans = sum, t;
    for (i = 0; i < l_r; i++)
    {
        t = sum - ((i < l_f) ? v[i] : 0) * pow(2, i);
        if (l <= t && t <= r)
            ans = max2(t, ans);
    }
    if (l_r > 1)
        ans = max2(ans, func2(l_r - 1, true, true));
    return ans;
    return 0;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll maxv, maxans, t, ans;
    l = 0;
    //cin >> x >> y >> l >> r;
    ll i;
    //cout << (x | y) << "\n";
    for (x = 1; x < 50; x++)
    {
        for (y = 1; y < 50; y++)
        {
            maxv = 0;
            maxans = 0;
            for (i = 1; i < 2 * max(x, y); i++)
            {
                r = i;
                t = (x & i) * (y & i);
                if (t > maxv)
                {
                    maxv = t;
                    maxans = i;
                }
                br.clear();
                bl.clear();
                v.clear();
                ans = func();
                if (ans != maxans)
                    cout << x << " " << y << " " << i << " " << t << " " << maxans << " " << ans << "\n";
                if ((ans - maxans) > 10 || (maxans - ans) > 10)
                    cout << "*";
            }
        }
    }
    return 0;
}

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t, i;
//     cin >> t;
//     for (i = 0; i < t; i++)
//     {
//         //cout<<"Case #"<<i+1<<": ";
//         bl.clear();
//         br.clear();
//         v.clear();
//         func();
//         cout << "\n";
//     }
// }