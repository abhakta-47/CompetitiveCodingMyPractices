#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n;
    cin >> n;
    for (int i = 1; i <= (n / 2 - 1); i++)
        cout << 2 * i << " " << 2 * i - 1 << " ";
    if (n % 2 == 0)
        cout << n << " " << n - 1;
    else
        cout << n << " " << n - 2 << " " << n - 1;

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
