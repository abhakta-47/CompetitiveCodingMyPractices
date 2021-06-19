#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, l, r;
    cin >> n >> l >> r;
    ll i;
    // cout << l << " " << r << "\n";
    vector<ll> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    // for (i = 0; i < n; i++)
    //     cout << arr[i] << ", ";
    // cout << "\n";

    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        auto pos1 = lower_bound(arr.begin(), arr.end(), l - arr[i]);
        auto pos2 = --(upper_bound(arr.begin(), arr.end(), r - arr[i]));
        // cout << arr[i] << " ="
        //      << min(arr[i], l - arr[i]) << "," << min(arr[i], r - arr[i]) << " = "
        //      << pos1 - arr.begin() << " "
        //      << pos2 - arr.begin() << ", ";
        ans += (pos2 - pos1 + 1) - (pos1 <= arr.begin() + i && arr.begin() + i <= pos2 ? 1 : 0);
        // cout << ans;
        // cout << "\n";
    }

    cout << ans / 2;
    // cout << "\n";
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
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
