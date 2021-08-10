#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, k, x;
    cin >> n >> k;
    pair<ll, ll> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = {x, i};
    }
    sort(a, a + n);
    ll nSS = 0;
    for (int i = 1; i < n; i++)
        if (a[i - 1].second + 1 != a[i].second)
            ++nSS;
    ++nSS;
    cout << (nSS <= k ? "Yes" : "No");

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
