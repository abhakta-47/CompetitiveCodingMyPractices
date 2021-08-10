#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int test(int n, int m)
{

    set<int> s;

    for (int i = 0; i <= m; i++)
    {
        cout << (n ^ i) << " ";
        s.insert(n ^ i);
    }
    cout << " = ";
    int k = 0;
    for (auto is : s)
        if (is != k++)
            return --k;
    return (*s.rbegin()) + 1;
}

void sol()
{

    // n=0 => m+1
    //

    ll n, m;
    cin >> n >> m;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    //cin>>t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
