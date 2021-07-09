#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back

void sol()
{
    ll a, b;
    cin >> a >> b;
    if (a < b)
    {
        ll t = a;
        a = b;
        b = t;
    }

    // a>=b
    ll maxGcd = a - b;
    ll dif = maxGcd ? min((b / maxGcd + 1) * maxGcd - b, b % maxGcd) : 0;
    // if (maxGcd != 0)
    // cout<<
    // cout << a << " " << b << " " << maxGcd << " " << b % maxGcd << "  ";
    cout << maxGcd << " " << dif;

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
