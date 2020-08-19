#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int n;

class Graph
{
    int V; // No. of vertices

    //graph containing vector
    vector<vector<int>> adj;
    vector<bool> visited;

    // A recursive function used by DFS
    void DFSUtil(int v)
    {
        // Mark the current node as visited and
        // print it
        visited[v] = true;
        // //cout << v << " ? " << visited[v] << " ";
        // Recur for all the vertices adjacent
        // to this vertex
        int i;
        for (i = 0; i < adj[v].size(); ++i)
        {
            // //cout << v << " -> " << adj[v][i] << "\n";
            if (!visited[adj[v][i]])
                DFSUtil(adj[v][i]);
        }
    }

public:
    vector<int> node_distants;

    Graph(int V) // Constructor
    {
        this->V = V;
        adj.resize(V + 1);
        node_distants.resize(V + 1);
        visited.resize(V + 1, false);
    }

    void addEdge(int v, int w)
    {
        // cout << "joining " << v << " " << w << "\n";
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // for non-direcrted graph
        // //cout << adj[v].size() << " " << adj[v][adj[v].size() - 1] << " " << adj[w].size() << " " << adj[w][adj[w].size() - 1] << "\n";
    }

    void visitReset()
    { //reset visit array to zero
        for (int i = 0; i <= V; i++)
            visited[i] = false;
    }

    void DFS(int v)
    {
        visitReset();
        DFSUtil(v);
    }

    int nComponents()
    {
        visitReset();
        int k = 0;
        for (int i = 1; i <= V; i++)
        {
            //cout << i << " = " << k << " ? " << visited[i] << "\n";

            if (!visited[i])
            {
                DFS(i);
                ++k;
            }
            // for (int i = 0; i <= V; i++)
            //cout << visited[i] << " ";
            //cout << "\n\n";
        }
        return k;
    }

    void BFS(int x)
    {
        visitReset();
        queue<int> temp;
        temp.push(x);
        visited[x] = true;
        while (!temp.empty())
        {
            x = temp.front();
            cout << x << " -> ";
            temp.pop();
            for (int i = 0; i < adj[x].size(); i++)
            {
                cout << adj[x][i] << " ";
                if (!visited[adj[x][i]])
                {
                    visited[adj[x][i]] = true;
                    temp.push(adj[x][i]);
                }
            }
            cout << "\n";
        }
    }

    int minDistance(int s, int e)
    {
        visitReset();
        int i;
        for (i = 0; i <= V; i++)
            node_distants[i] = -1;
        queue<int> temp;
        temp.push(s);
        visited[s] = true;
        node_distants[s] = 0;
        while (!temp.empty())
        {
            s = temp.front();
            // cout << s << " -> ";
            temp.pop();
            for (int i = 0; i < adj[s].size(); i++)
            {
                // cout << adj[s][i] << "=";
                if (!visited[adj[s][i]])
                {

                    visited[adj[s][i]] = true;
                    temp.push(adj[s][i]);
                    node_distants[adj[s][i]] = node_distants[s] + 1;

                    if (adj[s][i] == e)
                        return node_distants[e];
                }
                // cout << node_distants[adj[s][i]] << " ";
            }
            // cout << "\n";
        }

        // int k = 0;
        // for (i = 1; i < node_distants.size(); i++)
        // {
        //     // cout << i << "=" << node_distants[i] << "\n";
        //     if (node_distants[i] == e)
        //         ++k;
        // }

        // return k;
    }
};

int calCulator(int i, int j)
{
    return (i * n + j);
}

int func()
{
    cin >> n;
    char a[n][n];
    Graph g(n * n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
            // cout<<a[i][j]<<" ";
        }
    }

    int s, e;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 'T')
                continue;

            if (a[i][j] == 'S')
                s = calCulator(i, j);

            if (a[i][j] == 'E')
                e = calCulator(i, j);

            if (i != 0)
                if (a[i - 1][j] != 'T')
                    g.addEdge(calCulator(i, j), calCulator(i - 1, j));
            if (i != n - 1)
                if (a[i + 1][j] != 'T')
                    g.addEdge(calCulator(i, j), calCulator(i + 1, j));
            if (j != 0)
                if (a[i][j - 1] != 'T')
                    g.addEdge(calCulator(i, j), calCulator(i, j - 1));
            if (j != n - 1)
                if (a[i][j + 1] != 'T')
                    g.addEdge(calCulator(i, j), calCulator(i, j + 1));
        }
    }

    cout << g.minDistance(s, e);

    // for (i = 0; i < n ; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    t = 1;
    //cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
