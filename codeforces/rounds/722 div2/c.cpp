#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

class Node
{
    pair<int, int> lr;
    int id;

    Node(pair<int, int> p, int x) : lr(p), id(x)
    {
    }
}

void
sol()
{
    int n;
    cin >> n;
    Node nodes[n + 1];
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        nodes[i] = Node({l, r}, i);
    }
    sort()

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
