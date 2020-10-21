#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

long long diff(long long x, long long y, long long n)
{
    if (x < y)
    {
        x = x + y;
        y = x - y; // x+y-y=x
        x = x - y; //  x+y-x=y
    }

    return min((x - y), (n - x + y));
}

int func()
{
    int w, n;
    cin >> w >> n;
    int i, init[w], pos[n] = {0};
    for (i = 0; i < w; i++)
    {
        cin >> init[i];
        ++pos[init[i]];
    }
    int max_dis = 0, k = 0;
    vector<int> opp_pos;
    for (i = 0; i < w - 1; i++)
    {
        if (pos[i] != 0)
        {
            int dist = diff(i, k, n);
            if (dist > max_dis)
            {
                opp_pos.clear();
                opp_pos.push_back(((i > n / 2) ? (i - n / 2) : (i + n / 2)));
            }
            else if (dist == max_dis)
                opp_pos.push_back(((i > n / 2) ? (i - n / 2) : (i + n / 2)));
            k = i;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    //t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}
