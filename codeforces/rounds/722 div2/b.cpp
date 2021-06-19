#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n = 0;
    cin >> n;
    ll arr[n];
    ll l = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        l = min(l, arr[i]);
    }
    ll ans = n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == l)
            ans--;
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
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
