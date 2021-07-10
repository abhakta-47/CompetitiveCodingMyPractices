#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, k;
    cin >> n >> k;
    ll p[k], t[n], x;
    memset(t, 1000'001, sizeof(t));
    for (int i = 0; i < k; i++)
        cin >> p[i];
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        t[p[i] - 1] = x;
    }

    // for (auto it : t)
    // cout << it << " ";
    // cout << "\n";

    // x = t[0];
    for (int i = 1; i < n; i++)
    {
        t[i] = min(t[i], (t[i - 1] + (ll)1));
        // x = t[i];
    }

    // x = t[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        t[i] = min(t[i], (t[i + 1] + (ll)1));
        // x = t[i];
    }

    for (auto it : t)
        cout << it << " ";

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
