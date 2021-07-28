#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll *a, n;
ll MOD = 998244353;
ll ansSum = 0;
void allSum(ll i, ll sum, ll cMin)
{

    if (i == n)
    {
        cout << sum << "\n";
        ansSum = (ansSum + sum % MOD) % MOD;
        return;
    }

    cout << a[i] << " ";

    if (a[i] == -1)
    {
        // ignore
        allSum(i + 1, sum, cMin);
        // take in account
        allSum(i + 1, sum, (cMin + 1) % MOD);
    }
    else
    {
        // ignore
        allSum(i + 1, sum, cMin);
        // take in accout, pop
        if (cMin > 0)
            allSum(i + 1, sum, (cMin - 1) % MOD);
        // take in account, push
        allSum(i + 1, (sum + a[i]) % MOD, cMin);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    char c;
    ll v;
    a = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == '+')
            cin >> v;
        else
            v = -1;
        a[n - 1 - i] = v;
    }

    allSum(0, 0, 0);
    cout << ansSum;
}
