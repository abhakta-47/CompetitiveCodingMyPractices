#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n;
    cin >> n;
    int a[n], i;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            v.push_back(a[i]);
    }
    for (int i = 0; i < n; i++)
        if (a[i] % 2)
            v.push_back(a[i]);

    int ans = 0;
    for (i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (__gcd(v[i], 2 * v[j]) > 1)
            {
                ++ans;
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
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
