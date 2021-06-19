#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
ll MOD = 1e9 + 7;
class Graph
{
public:
    int v; //number of vertices
    vector<vector<ll>> edges;
    vector<bool> visited;
    vector<ll> values;
    Graph(int n)
    {
        v = n;
        edges.resize(n + 1);
        visited.resize(n + 1, false);
        values.resize(n + 1);
        values[1] = 1;
    }
    void addEdge()
    {
        ll x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    void display()
    {
        for (int i = 1; i <= v; i++)
        {
            clog << i << "->";
            for (auto i1 : edges[i])
                clog << i1 << ",";
            clog << "\n";
        }
    }
    void visitedReset()
    {
        visited.clear();
        visited.resize(v + 1, false);
    }
    ll dfs(ll n)
    {
        visited[n] = true;

        vector<pair<ll, ll>> childValues;
        for (auto child : edges[n])
            if (!visited[child])
                childValues.push_back({dfs(child), child});

        ll res = (ll)0, k = (ll)1;
        sort(childValues.begin(), childValues.end(), greater<pair<ll, ll>>());
        clog << n << "->";
        for (auto childValue : childValues)
        {
            values[childValue.second] = k;
            res = (res + ((childValue.first) * (k)));
            k = (k + 1);
            clog << childValue.first * (k - 1) << ",";
        }
        clog << " +1=" << ((ll)1 + res) << "\n";
        return ((ll)1 + res);
    }
    void setValue(ll n, ll value)
    {
        if (n == 1)
            visitedReset();

        visited[n] = true;
        for (auto child : edges[n])
            if (!visited[child])
            {
                values[child] = (values[child] % MOD * value % MOD) % MOD;
                setValue(child, values[child]);
            }
    }
    ll sumValues()
    {
        ll sum = 0;
        for (auto value : values)
            sum = (sum % MOD + value % MOD) % MOD;
        return sum;
    }
};

void sol()
{
    int n, x;
    cin >> n >> x;
    Graph g(n);
    int i;
    for (i = 0; i < n - 1; i++)
        g.addEdge();
    // g.display();
    g.dfs(1);
    g.setValue(1, x);
    cout << g.sumValues();
    clog << (x % MOD * g.dfs(1)) % MOD;
    clog << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clog.tie(NULL);
    ll t, tc = 1;
    t = 1;
    cin >> t;
    while (t--)
    {
        cerr << "Case #" << tc++ << ":\n";
        sol();
        clog << "_________________\n";
        cout << "\n";
    }
}
