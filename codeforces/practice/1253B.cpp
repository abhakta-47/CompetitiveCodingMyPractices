#include <bits/stdc++.h>

using namespace std;

#define ll long long

int func()
{
    ll n;
    cin >> n;
    ll i, em[n];

    for (i = 0; i < n; i++)
        cin >> em[i];

    ll emc[n] = {0};

    for (i = 0; i < n; i++)
    {
        if (em[i] > 0 && emc[em[i]] == 0)
            emc[]
    }

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