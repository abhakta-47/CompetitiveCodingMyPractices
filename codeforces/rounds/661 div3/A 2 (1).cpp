#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n-1; i++)
    {
        if (a[i + 1] - a[i] > 1)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    //t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
