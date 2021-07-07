#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    sort(h, h + n);

    if (n == 2)
    {
        cout << h[0] << " " << h[1];
        return;
    }

    ll minDif = h[1] - h[0];
    for (int i = 1; i < n - 1; i++)
        minDif = min(minDif, h[i + 1] - h[i]);

    int x;
    for (int i = 0; i < n - 1; i++)
        if (h[i + 1] - h[i] == minDif)
        {
            for (int j = i + 1; j < n; j++)
                cout << h[j] << " ";
            for (int j = 0; j <= i; j++)
                cout << h[j] << " ";
            break;
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
