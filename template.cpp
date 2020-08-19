#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<bool> v;
int g_in()
{
    int p, c;
    cin >> p >> c;
    g[p].pb(c);
    return 0;
}
int k = 0;
int n_children[10000] = {0};
int bfs(int u)
{

    v[u] = true;

    // Enqueue all adjacent of f and mark them ved
    for (auto i = 0; i < g[u].size(); i++)
    {
        n_children[u] += ((v[g[u][i]] ? n_children[g[u][i]] : bfs(g[u][i])) + 1);
    }

    return n_children[u];
}

int func()
{

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
