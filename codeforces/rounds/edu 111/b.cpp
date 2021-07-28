#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    if (b >= 0)
    {
        cout << s.length() * (a + b);
        return;
    };
    ll k = 1;
    vector<ll> freq;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            ++k;
        else
        {
            freq.push_back(k);
            k = 1;
        }
    }
    freq.push_back(k);
    ll ans = a * s.length() + b * (freq.size() / 2) + b;
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
