//http://codeforces.com/contest/1433/problems
// :)
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{
    int n;
    cin >> n;
    vector<int> v;
    int x, i, k = 0, total = 0;

    bool start_0 = false, end_0 = false;

    for (i = 0; i < n; i++)
    {
        // if (i != n)
        cin >> x;
        if (i == 0 && x == 0)
            start_0 = true;
        if (i == n - 1 && x == 0)
            end_0 = true;

        if (x == 1)
        {
            v.push_back(k);
            total += k;
            k = 0;
        }
        else
            ++k;
    }
    if (x == 0)
    {
        v.push_back(k);
        total += k;
        k = 0;
    }
    // cout << "    " << total << " " << (start_0 ? v[0] : 0) << " " << (end_0 ? v[v.size() - 1] : 0) << "    ";
    cout << total - (start_0 ? v[0] : 0) - (end_0 ? v[v.size() - 1] : 0);
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
