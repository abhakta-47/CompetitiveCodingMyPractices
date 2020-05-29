#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll x, y, l, r, l_r2;
ll l_r;
vector<ll> br, bl, sum1, sum2, v;
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

ll max2(ll t1, ll t2)
{
    if (func4(t1) > func4(t2))
        return t1;
    else if (func4(t2) > func4(t1))
        return t2;
    else
        return min(t1, t2);
}

vector<ll> func2(ll i, bool sg, bool gs)
{
    ll t, bit_l, bit_r, bit_f;
    ll x = i - 1;
    vector<ll> funcOut;
    funcOut.resize(i);
    while (--i >= 0)
    {
        bit_l = bl[i];
        bit_f = v[i];
        bit_r = br[i];

        // sg smaller than greater && gs greater than smaller
        if (sg && gs)
            t = bit_f;
        else if (~sg && gs)
        {
            if (bit_r == 0 && bit_f == 1)
                t = 0;
            else
                t = bit_f;
            if (t != bit_r)
                sg = true;
        }
        else if (sg && ~gs)
        {
            if (bit_l == 1 && bit_f == 0)
                t = 1;
            else
                t = bit_f;
            if (t != bit_l)
                gs = true;
        }
        else
        {
            if (bit_l == bit_r)
                t = bit_l;
            else
            {
                t = bit_f;
                if (t == bit_r)
                    gs = true;
                if (t == bit_l)
                    sg = true;
                l_r2 = i;
            }
        }
        //cout << i << " " << bit_r << " " << bit_f << " " << bit_l << " " << t << " " << gs << sg << " ";
        funcOut[i] = t; //(t * pow(2, i) + funcOut[funcOut.size() - 1]);
        //cout << funcOut[i] << "\n ";
    }

    return funcOut;
}

ll func()
{
    br.clear();
    bl.clear();
    sum1.clear();
    sum2.clear();
    v.clear();
    //input
    //cin >> x >> y >> l >> r;
    // x = 3;
    // y = 5;
    // l = 0;
    // r = 9;
    //cout << "*1\n";
    br = decToBinary(r);
    l_r = br.size();
    bl = decToBinary(l);
    v = decToBinary(x | y);
    bl.resize(l_r, 0);
    v.resize(l_r, 0);

    ll i, ans;
    sum2.resize(l_r);
    for (i = 0; i < l_r; i++)
    {
        if (i == 0)
            sum2[i] = v[i];
        else
            sum2[i] = sum2[i - 1] + v[i] * pow(2, i);
    }
    //cout << "*2\n";
    sum1 = func2(l_r, false, false);
    for (i = 1; i < l_r; i++)
        sum1[i] = sum1[i - 1] + sum1[i] * pow(2, i);

    // cout << "printing\n";
    // for (i = 0; i < sum1.size(); i++)
    //     cout << sum1[i] << " ";

    ans = sum1[l_r - 1];
    for (i = l_r2; i >= 1; i--)
    {
        if (v[i] == 1 && br[i] == 1)
        {
            ans = max2(ans, sum2[i - 1] + sum1[l_r - 1] - sum1[i]);
        }
    }
    ans = max2(ans, l);
    if (ans < l)
    {
        v.clear();
        v = decToBinary(ans);
        v.resize(l_r, 0);
        for (i = l_r2; i >= 0; i--)
        {
            if (bl[i] == 1 && v[i] == 0)
                ans += pow(2, i);
            else if (bl[i] == 0 && v[i] == 1)
                break;
        }
    }
    return ans;
}

// int main()
// {
//     func();
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << "in";
    ll maxv, maxans, t, ans;
    l = 0;
    //cin >> x >> y >> l >> r;
    ll i;
    //cout << (x | y) << "\n";
    for (x = 0; x < 50; x++)
    {
        for (y = 0; y < 50; y++)
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