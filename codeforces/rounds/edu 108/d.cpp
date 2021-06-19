#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n], b[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];

    ll pre[n + 1] = {0};
    for (i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i] * b[i];

    ll ans = pre[n], curSum = 0;
    for (int mid = 0; mid < n; mid++)
    {
        ll tmpSum = a[mid] * b[mid];

        for (int il = mid - 1, ir = mid + 1; 0 <= il && ir < n; il--, ir++)
        {
            // clog << curSum << ", ";
            tmpSum += a[il] * b[ir] + a[ir] * b[il];
            curSum = pre[il] + tmpSum + pre[n] - pre[ir + 1];
            ans = max(ans, curSum);
        }
        tmpSum = 0;
        for (int il = mid, ir = mid + 1; 0 <= il && ir < n; il--, ir++)
        {
            // clog << curSum << ", ";
            tmpSum += a[il] * b[ir] + a[ir] * b[il];
            curSum = pre[il] + tmpSum + pre[n] - pre[ir + 1];
            ans = max(ans, curSum);
        }
    }

    cout << ans;

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
