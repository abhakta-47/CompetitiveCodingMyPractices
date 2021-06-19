//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/array-modification-2-dc88ff8a/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];

    ll leftBest[n], rightBest[n];
    leftBest[0] = a[0];
    for (i = 1; i < n; i++)
        leftBest[i] = leftBest[i - 1] / 2 + a[i];
    rightBest[n - 1] = a[n - 1];
    for (i = n - 2; i >= 0; i--)
        rightBest[i] = rightBest[i + 1] / 2 + a[i];

    ll ans = 0;
    for (i = 0; i < n; i++)
        ans = max(ans, leftBest[i] + rightBest[i] - a[i]);
    cout << ans;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
