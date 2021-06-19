#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << " ";
    cout << "\n";
    int count = 0;
    for (int b = 2; b <= n; b++)
    {
        cout << m % b << ": " << b << "->";
        for (int a = 1; a < b; a++)
            if ((m % a) % b == (m % b) % a)
            {
                cout << a << ",";
                ++count;
            }
        cout << "\n";
    }
    cout << count;
    cout << "\n";
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
