#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int i;
    int l = s.length();

    int k1 = 0, k2 = 0;
    for (i = 0; i < l - 1; i++)
    {
        if (k1 == 0)
        {
            if (s[i] == 'A' && s[1 + i] == 'B')
            {
                k1 = 1;
                ++i;
            }
        }
        else
        {
            if (s[i] == 'B' && s[1 + i] == 'A')
                k2 = 1;
        }
    }

    int k3 = 0, k4 = 0;
    for (i = 0; i < l - 1; i++)
    {
        if (k3 == 0)
        {
            if (s[i] == 'B' && s[1 + i] == 'A')
            {
                k3 = 1;
                ++i;
            }
        }
        else
        {
            if (s[i] == 'A' && s[1 + i] == 'B')
                k4 = 1;
        }
    }

    if ((k1 == 1 && k2 == 1) || (k3 == 1 && k4 == 1))
        cout << "YES";
    else
        cout << "NO";
}