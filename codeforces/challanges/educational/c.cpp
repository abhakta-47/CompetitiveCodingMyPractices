#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int func()
{
    ll a, b;
    cin >> a >> b;
    ll i;
    cout << a << " " << b << "\n";
    for (i = 1; i <= 100; i++)
        cout << i << " " << (i % a) % b << " " << (i % b) % a << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}