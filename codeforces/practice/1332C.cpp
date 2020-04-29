#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll i, j;
    ll ans = 0;
    for (i = 0; i < k / 2; i++)
    {
        ll a[26] = {0};
        for (j = i; j < n; j += k)
            ++a[int(s[j]) - 97];

        for (j = k - i - 1; j < n; j += k)
            ++a[int(s[j]) - 97];
        sort(a, a + 26);
        //cout << i << "-" << n / k - a[25] << " ";
        ans += (2 * n / k - a[25]);
    }
    if (k % 2 != 0)
    {
        ll a[26] = {0};
        for (j = k / 2; j < n; j += k)
            ++a[int(s[j]) - 97];

        sort(a, a + 26);
        //cout << i << "-" << n / k - a[25] << " ";
        ans += (n / k - a[25]);
    }
    cout << ans;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}