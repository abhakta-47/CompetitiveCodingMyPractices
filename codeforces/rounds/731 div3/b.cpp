#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{

    string s;
    cin >> s;
    int posa;
    set<char> ss;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            posa = i;
        }
        ss.insert(s[i]);
    }
    int k = 0;
    for (auto i : ss)
    {
        if (i != int('a') + k)
        {
            cout << "NO";
            return;
        }
        ++k;
    }
    for (int i = posa; i < s.length() - 1; i++)
        if (s[i] >= s[i + 1])
        {
            cout << "NO";
            return;
        }

    for (int i = 0; i < posa; i++)
        if (s[i] <= s[i + 1])
        {
            cout << "NO";
            return;
        }
    cout << "YES";
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
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
