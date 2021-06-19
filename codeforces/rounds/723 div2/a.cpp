#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n;
    cin >> n;
    int a[2 * n];
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort(a, a + 2 * n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " " << a[i + n] << " ";
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
