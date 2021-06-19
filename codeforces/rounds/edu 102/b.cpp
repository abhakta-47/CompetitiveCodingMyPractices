#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

string str_multi(string s, int k)
{
    string r = "";
    while (k--)
        r = r + s;
    return r;
}

int func()
{
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;

    if (s1.length() < s2.length())
        swap(s1, s2);

    int l1 = s1.length(), l2 = s2.length();
    int lcm = l1 * l2 / __gcd(l1, l2);
    string ns1 = str_multi(s1, lcm / l1);
    string ns2 = str_multi(s2, lcm / l2);

    if (ns1 == ns2)
        cout << ns1;
    else
        cout << "-1";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    // t = 1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
