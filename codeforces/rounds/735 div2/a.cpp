#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{

    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, a[i] * a[i - 1]);
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
