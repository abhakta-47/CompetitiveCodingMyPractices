#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll n;
void sol(ll x)
{
    char c;
    cout << x << "\n";
    cin >> c1;
    cout << x + 1 << "\n";
    cin >> c;
    cout << x << "\n";
    cin >> c2;
    if (c1 != c2)
        addEdge(x, x + 1);
}

int main()
{
    ll n;
    cin >> n;
}
