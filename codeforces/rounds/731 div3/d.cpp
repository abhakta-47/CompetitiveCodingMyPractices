#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ll t;
    cout << 0 << " ";
    for (int i = 1; i < n; i++)
    {
        t = (x[i - 1] & (~x[i]));
        cout << t << " ";
        x[i] = x[i] ^ t;
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
