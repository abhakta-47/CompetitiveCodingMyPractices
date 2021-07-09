#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

float util(float c, float m, float p, float v, int x, float pro)
{
    // cout << pro << ", ";
    cout << c << " " << m << " " << p << " " << v << " " << x << " " << pro << "\n";
    float new_c, new_m, new_p, new_x, new_pro;
    float ans = 0;
    // for c
    if (c != 0)
        if (c <= v)
        {
            new_pro = pro * c;
            new_c = 0;
            new_x = x - 1;
            if (new_m != 0)
                new_m = m + c / x;
            if (new_p != 0)
                new_p = p + c / x;
            ans += util(new_c, new_m, new_p, v, new_x, new_pro);
        }
        else
        {
            new_pro = pro * c;
            new_c = c - v;
            if (new_m != 0)
                new_m = m + v / x;
            if (new_p != 0)
                new_p = p + v / x;
            ans += util(new_c, new_m, new_p, v, new_x, new_pro);
        }
    // for m
    // if (m != 0)
    //     if (m <= v)
    //     {
    //         new_pro = pro * m;
    //         new_m = 0;
    //         new_x = x - 1;
    //         if (new_c != 0)
    //             new_c = c + m / x;
    //         if (new_p != 0)
    //             new_p = p + m / x;
    //         ans += util(new_c, new_m, new_p, v, new_x, new_pro);
    //     }
    //     else
    //     {
    //         new_pro = pro * m;
    //         new_m = m - v;
    //         if (new_c != 0)
    //             new_c = c + v / x;
    //         if (new_p != 0)
    //             new_p = p + v / x;
    //         ans += util(new_c, new_m, new_p, v, new_x, new_pro);
    //     }
    // for p
    ans += pro * p;
    return ans;
}

void sol()
{
    float c, m, p, v;
    cin >> c >> m >> p >> v;
    cout << util(c, m, p, v, 3, (float)1);

    return;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
        cout << "\n";
    }
}
