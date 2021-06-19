#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    pair<int, int> p[4];
    int x, i;
    for (i = 0; i < 4; i++)
    {
        cin >> x;
        p[i] = {x, i};
    }
    sort(p, p + 4);
    int p1 = max(p[2].second, p[3].second), p2 = min(p[2].second, p[3].second);
    if (p2 <= 1 && p1 > 1)
        cout << "YES";
    else
        cout << "NO";

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
