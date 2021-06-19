//http://codeforces.com/contest/1433/problems
// :)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

unsigned long long int fact(int n)
{
    unsigned long long int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
unsigned long long int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int func(int n)
{

    cin >> n;
    // cout << n << "-> " << nCr(n, n / 2) << " " << fact(n / 2 - 1) << " " << fact(n / 2 - 1) << "   ";
    // cout << n << " -> ";
    cout << nCr(n, n / 2) * fact(n / 2 - 1) * fact(n / 2 - 1) / 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    // t = 1;
    cin >> t;
    func(t);
}
