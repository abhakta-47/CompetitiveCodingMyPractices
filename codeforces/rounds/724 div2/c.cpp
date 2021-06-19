#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n;
    string s;
    cin >> n >> s;
    map<pair<int, int>, int> m;
    int xd = 0;
    if (s[0] == 'D')
        ++xd;

    ++m[{xd, 1}];
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'D')
            ++xd;
        ll gcdx = __gcd(xd, i + 1);
        cout << ++m[{xd / gcdx, (i + 1) / gcdx}] << " ";
    }
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
