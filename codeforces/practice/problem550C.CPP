#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int func()
{
    int n;
    string s;
    cin >> s;
    s = "00" + s;
    n = s.length();
    int i, j, k;
    int x, y, z, flag = 0;
    for (i = n - 1; i >= 2; i--)
    {
        x = int(s[i]) - 48;
        for (j = i - 1; j >= 1; j--)
        {

            y = int(s[j]) - 48;
            for (k = j - 1; k >= 0; k--)
            {

                z = int(s[k]) - 48;
                //cout << z << y << x << " ";
                if ((100 * z + 10 * y + x) % 8 == 0)
                {

                    z = k;
                    y = j;
                    x = i;
                    flag = 1;
                    //cout << k << j << i << " ";
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }

    if (flag == 0)
    {
        cout << "NO";
        return 0;
    }
    else
        cout << "YES\n";

    for (i = 2; i < s.length(); i++)
    {
        if (i <= z || i == y || i == x)
            cout << s[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    t = 1; //cin>>t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}