// https://codeforces.com/problemset/problem/59/A
// accepted :)
#include <bits/stdc++.h>

using namespace std;

#define ll long long

string s;

void changeCase(bool c)
{
    ll l = s.length(), i;
    //cout << c;
    for (i = 0; i < l; i++)
    {
        if (65 <= int(s[i]) && int(s[i]) <= 90)
        {
            if (c)
                cout << char(int(s[i]) + 32);
            else
                cout << s[i];
        }
        else
        {
            if (c)
                cout << s[i];
            else
                cout << char(int(s[i]) - 32);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    ll l = s.length();
    ll a = 0, b = 0, i;
    for (i = 0; i < l; i++)
        if (65 <= int(s[i]) && int(s[i]) <= 90)
            ++a;
        else
            ++b;
    //cout << a << b;
    if (a <= b)
        changeCase(true);
    else
        changeCase(false);
}