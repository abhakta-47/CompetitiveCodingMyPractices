#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

bool shouldStop(int t, int g1, int g2)
{
}

void sol()
{
    string s;
    cin >> s;
    int a[2][3];
    for (int i = 0; i < 10; i++)
    {
        a[i % 2][s[i] == '?' ? 2 : s[i] - '0']++;
    }
    return;
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
        sol();
        cout << "\n";
    }
}
