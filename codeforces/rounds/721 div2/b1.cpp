#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

string sol()
{
    int n;
    string s;
    cin >> n >> s;
    int c_0 = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            ++c_0;

    if (c_0 == 0)
        return "DRAW";

    if (c_0 == 1)
        return "BOB";

    if (c_0 % 2 == 0)
        return "BOB";

    return "ALICE";
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
        cout << sol();
        cout << "\n";
    }
}
