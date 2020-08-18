#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
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

int main()
{
    int d, ans = INFINITY;
    cin >> n >> d;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++)
        g_in();
    v.resize(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (v[i])
            continue;
        k = 0;
        bfs(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (n_children[i] < ans)
            ans = n_children[i];
    }
    cout << ans;
}