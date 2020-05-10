#include <bits/stdc++.h>

using namespace std;

#define ll long long

//ll l_l, l_r, l_f, x, y, l, r, p;
ll x, y, l, r;
set<ll> bx, by, bl, br, bans;

set<ll> decToBinary(ll n)
{
    set<ll> t;
    t.clear();
    int i = 0;
    while (n > 0)
    {
        if (n % 2 == 1) //{
            t.insert(i);
        //cout<<i<<" ";}
        n = n / 2;
        i++;
    }
    return t;
}

int func()
{
    cout << "in func " << x << y << l << r << " ";
    bx.clear();
    by.clear();
    bl.clear();
    br.clear();
    bans.clear();
    //ll x, y, l, r;
    ll ans = 0;
    //cin >> x >> y >> l >> r;
    if (x * y == 0)
        ans = l;
    else if (l == r)
        ans = l;
    else
    {
        // always x > y
        if (x < y)
        {
            x = x + y;
            y = x - y;
            x = x - y;
        }

        // binarise
        bx = decToBinary(x);
        by = decToBinary(y);
        bl = decToBinary(l);
        br = decToBinary(r);

        // main Calculations

        ll xbit, ybit, lbit, rbit;
        bool flag = false;
        for (ll i = *(--bl.end()); i >= 0; --i)
        {
            rbit = (br.find(i) == br.end()) ? 0 : 1;
            lbit = (bl.find(i) == bl.end()) ? 0 : 1;
            xbit = (bx.find(i) == bx.end()) ? 0 : 1;
            ybit = (by.find(i) == by.end()) ? 0 : 1;

            if (flag)
            { // if ans is already less than r
                if (xbit == 1 || ybit == 1)
                    bans.insert(i);
            }
            else
            {
                if (rbit == 1)
                {
                    if (xbit == 1 && ybit == 1)
                        bans.insert(i);
                    else if (xbit == 1)
                    {
                        ll t1 = *(--bx.lower_bound(i)) + *(--by.lower_bound(i));
                        ll t2 = *(--br.lower_bound(i));
                        t2 = *(--by.upper_bound(t2)) + i;
                        if (t2 > t1)
                            bans.insert(i);
                    }
                    else if (ybit == 1)
                    {
                        ll t1 = *(--bx.lower_bound(i)) + *(--by.lower_bound(i));
                        ll t2 = *(--br.lower_bound(i));
                        t2 = *(--bx.upper_bound(t2)) + i;
                        if (t2 > t1)
                            bans.insert(i);
                    }
                }
            }

            // if ans is already less than r
            if (rbit == 1 && bans.find(i) == bans.end())
                flag = true;
        }

        set<ll>::iterator itr;

        for (itr = bans.begin(); itr != bans.end(); itr++)
            ans += pow(2, *itr);
    }

    return ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout << "in";
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
                ans = func();
                //if (ans != maxans)
                cout << "x-" << x << "  y-" << y << "  z-" << i << "  x&z-" << (x & i) << "  y&z-" << (y & i) << "  x&z*y&z-" << t << "  ans-" << maxans << "  myAns-" << ans; // << "\n";
                if (ans != maxans)
                    cout << " no";
                else
                    cout << " yes";
                // if ((ans - maxans) > 10 || (maxans - ans) > 10)
                //     cout << "*";
                cout << "\n";
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