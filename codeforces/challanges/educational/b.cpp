#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n, i;
    string s;
    cin >> s;
    n = s.length();
    bool flag = true;
    for (i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << s;
        return 0;
    }
    else
    {
        cout << s[0];
        for (i = 1; i < n; i++)
        {

            if (s[i] == s[i - 1])
            {
                if (s[i] == '0')
                    cout << 1;
                else
                    cout << 0;
            }
            cout << s[i];
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}