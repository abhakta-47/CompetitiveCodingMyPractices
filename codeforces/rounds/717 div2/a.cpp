#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(x, s, e) for (int x = s; x < e; ++x)
#define arrIn(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

void sol()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    arrIn(a, n);
    loop(i, 0, n)
    {
        int x = min(k, a[i]);
        a[n - 1] += x;
        a[i] -= x;
        k -= x;
        cout << a[i] << " ";
    }
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
