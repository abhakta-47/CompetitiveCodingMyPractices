#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

vector<int> a;

int counter(int n, int cnt)
{
    int i, k = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            ++cnt;
        else if (a[i] < a[i - 1])
            --cnt;
        if (cnt < 0 || cnt > 3)
        {
            ++k;
            cnt = 0;
        }
    }
    return k;
}

int func()
{
    int n;
    cin >> n;
    a.resize(n);
    int i;

    for (i = 0; i < n; i++)
        cin >> a[i];

    int ans = INT_MAX, max_ = 0, cnt = 0, k = 0;
    bool f;
    // for (i = 0; i < 4; i++)
    // ans = min(ans, counter(n, i));

    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            ++cnt;
        else if (a[i] < a[i - 1])
            --cnt;
        else
            continue;
        max_ = max(max_, cnt);
        if (cnt < 0)
        {
            f = false;
            for (int j = i; j >= i - 4; j--)
                if (a[j - 1] <= a[j])
                {
                    f = true;
                    break;
                }
            if (!f)
            {
                ++k;
                a[i-1]=-1;
                cnt = 0;
            }
        }
        if (cnt > 3)
        {
            f = false;
            for (int j = i; j >= i - 4; j--)
                if (a[j - 1] >= a[j])
                {
                    f = true;
                    break;
                }
            if (f)
                cnt = 3;
            else
            {
                ++k;
                cnt = 0;
                a[i-1]=-1;
            }
        }
    }

    cout << k;

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
