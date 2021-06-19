#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll k;
string s;

ll recurse(int p)
{
    if (p < (1 << (n - 1)))
    if()

        if (s[p] == '0')
            return recurse(2 * p + 1);
    if (s[p] == '1')
        return recurse(2 * p + 2);

    return recurse(2 * p + 1) * recurse(2 * p + 1);
}

void sol()
{
    cin >> k;
    cin >> s;
    reverse(s.begin(), s.end());

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
