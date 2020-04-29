#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll l = 0, k = 0, x = 0, n = s1.length();
    ll i;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {

        if (s1[i] == s2[i])
            ++x;
        else if (x != 0)
        {

            v.push_back(x);
            x = 0;
        }

        if (s1[i] != s2[i])
            ++l;

        if ((s1[i] != s2[i]) && (s1[i - 1] == s2[i - 1]))
            ++k;
    }

    if (s1[0] == s2[0])
        v.erase(v.begin());
    if (s1[n - 1] == s2[n - 1])
        v.erase(--v.end());

    sort(v.begin(), v.end());

    //cout << l * k << " ";

    for (i = 0; i < v.size(); i++)
    {
        //cout << v[i] << " ";
        if (l > (v[i] * (k - 1)))
        {
            l += x;
            --k;
        }
    }

    if (n > l * k)
        cout << l * k;
    else
    {
        cout << n;
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