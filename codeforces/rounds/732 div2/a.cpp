#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<ll> lhs, rhs;
    for (auto i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            for (ll j = 0; j < (a[i] - b[i]); j++)
                lhs.push_back(i);
        else if (a[i] < b[i])
            for (ll j = 0; j < (b[i] - a[i]); j++)
                rhs.push_back(i);
    }

    if (lhs.size() != rhs.size())
    {
        cout << -1 << "\n";
        return;
    }
    else
    {
        cout << lhs.size() << "\n";
        for (int i = 0; i < lhs.size(); i++)
            cout << lhs[i] + 1 << " " << rhs[i] + 1 << "\n";
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
        // cout << "\n";
    }
}
