#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n];
    pair<ll, ll> ap[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ap[i] = {a[i], i};
    }
    vector<ll> lis;
    ll l_lis[n];
    lis.push_back(a[0]);
    l_lis[0] = 0;
    ll ind, ans = 0;
    for (int i = 1; i < n; i++)
    {
        ind = upper_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        cout << a[i] << " " << ind << ", ";
        lis.push_back(a[i]);
        sort(lis.begin(), lis.end());
        ans += pow(2, i - ind) * ind;
    }

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
