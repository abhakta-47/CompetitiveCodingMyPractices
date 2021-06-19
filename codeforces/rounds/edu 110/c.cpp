#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    string s;
    cin >> s;
    // clog << s << "  ";
    ll n = s.length();
    ll k = 1, ans = 1, last_pos = 0;
    char last_char = s[0];
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == '?')
            ++k;
        else
        {
            if (last_char == '?')
                ++k;
            else if (s[i] == last_char && (i - last_pos) % 2 == 0)
                ++k;
            else if (s[i] != last_char && (i - last_pos) % 2 == 1)
                ++k;
            else
                k = i - last_pos;
        }
        if (s[i] != '?')
        {
            last_char = s[i];
            last_pos = i;
        }
        // clog << i - k + 1 << "-" << i << ", ";
        ans += k;
    }

    cout << ans;
    // clog << ans;

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
        // clog << "Case #: ";
        sol();
        cout << "\n";
        // clog << "\n";
    }
}
