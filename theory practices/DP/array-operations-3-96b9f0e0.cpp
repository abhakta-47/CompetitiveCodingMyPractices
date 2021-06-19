#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int maxSumContiSubArray(int *a, int size, int *ans)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }

        ans[i] = max_so_far;
    }
    // cout << "Maximum contiguous sum is "
    //      << max_so_far << endl;
    // cout << "Starting index " << start
    //      << endl
    //      << "Ending index " << end << endl;
    return max_so_far;
}

void sol()
{
    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> maxLeft(n, 0), maxRight(n, 0);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        maxLeft[i] = max(sum, maxLeft[i]);
        sum = max(sum, 0ll);
    }
    sum = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        maxRight[i] = max(maxRight[i], sum);
        sum = max(sum, 0ll);
    }
    ll ans = 0, best = 0;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, best + maxRight[i]);
        best = max(best, maxLeft[i]);
    }
    ans = max(ans, best);
    cout << ans;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, i = 0;
    //t=1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << ++i << ": ";
        sol();
        cout << "\n";
        // if (i > 11)
        // break;
    }
}
