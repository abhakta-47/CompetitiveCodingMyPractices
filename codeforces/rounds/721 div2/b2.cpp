#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

string sol_palindrome(int c_0)
{
    if (c_0 == 0)
        return "DRAW";

    if (c_0 == 1)
        return "BOB";

    if (c_0 % 2 == 0)
        return "BOB";

    return "ALICE";
}

string sol()
{
    int n;
    string s;
    cin >> n >> s;

    int c_0 = 0, c_p_0 = 0, c_np_0 = 0;

    for (int i = 0; i < n; i++)
    {
        // cout << i << ": " << s[i] << " " << s[n - i - 1] << " ";
        if (s[i] == '0')
            ++c_0;
        if (s[i] == '0' && s[i] != s[n - i - 1])
            ++c_np_0;
        // cout << c_0 << " " << c_np_0 << "\n";
    }

    c_p_0 = c_0 - c_np_0;
    clog << c_0 << " " << c_np_0 << " " << c_p_0 << "  ";

    if (c_np_0 == 0)
        return sol_palindrome(c_p_0);
    else if (n % 2 == 1 && c_0 == 2 && s[n / 2] == '0')
        return "DRAW";

    return "ALICE";
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
        cout << sol();
        cout << "\n";
    }
}
