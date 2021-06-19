#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int MOD = 1E9 + 7;

class Graph
{

public:
    ll V;
    vector<vector<ll>> adj;
    vector<ll> subval, val;
    vector<bool> visited;

    Graph(ll V) // Constructor
    {
        this->V = V;
        adj.resize(V + 1);
        visited.resize(V + 1, false);
        subval.assign(V + 1, 1);
        val.assign(V + 1, 0);
    }

    void addEdge(ll v, ll w)
    {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // for non-direcrted graph
    }

    void addAllEdges()
    {
        ll x, y;
        for (int i = 0; i < V - 1; i++)
        {
            cin >> x >> y;
            addEdge(x, y);
        }
    }

    void dfs(ll curNode, ll parent = -1)
    {
        for (auto x : adj[curNode])
            if (x != parent)
                dfs(x, curNode);

        vector<pair<ll, ll>> tmp;
        for (auto x : adj[curNode])
            if (x != parent)
                tmp.push_back({subval[x], x});
        sort(tmp.rbegin(), tmp.rend());

        ll k = 1;
        for (auto [_val, id] : tmp)
            val[id] = k++;

        for (auto x : adj[curNode])
            if (x != parent)
                subval[curNode] += val[x] * subval[x];
    }

    void answer(ll x)
    {
        cout << subval[0] % MOD * x % MOD;
    }
};

void sol()
{
    ll n, x;
    cin >> n >> x;
    Graph g(n);
    g.addAllEdges();

    g.dfs(1);

    g.answer(x);

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
