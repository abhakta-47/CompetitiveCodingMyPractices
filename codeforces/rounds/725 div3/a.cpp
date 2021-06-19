#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n;
    cin >> n;
    int a[n], max_pos = 0, min_pos = 0;
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > a[max_pos])
            max_pos = i;
        else if (a[i] < a[min_pos])
            min_pos = i;
    }
    ll min_val = min(min_pos + 1, max_pos + 1);
    ll max_val = max(min_pos + 1, max_pos + 1);
    ll ans = min(max_val, min(n - (min_val - 1), min_val + n - (max_val - 1)));
    cout << ans;
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
