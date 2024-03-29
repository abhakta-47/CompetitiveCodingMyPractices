// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
// done :)
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

class Graph
{
    int V; // No. of vertices

    //graph containing vector
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> node_distants;

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
    Graph(int V) // Constructor
    {
        this->V = V;
        adj.resize(V + 1);
        node_distants.resize(V + 1);
        visited.resize(V + 1, false);
    }

    void addEdge(int v, int w)
    {
        // //cout << "joining " << v << " " << w << " ";
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
            // cout << x << " -> ";
            temp.pop();
            for (int i = 0; i < adj[x].size(); i++)
            {
                // cout << adj[x][i] << " ";
                if (!visited[adj[x][i]])
                {
                    visited[adj[x][i]] = true;
                    temp.push(adj[x][i]);
                }
            }
            // cout << "\n";
        }
    }

    int minDistance(int s, int e)
    {
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
    }
};

int func()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    int i, v, w;
    for (i = 0; i < m; i++)
    {
        cin >> v >> w;
        g.addEdge(v, w);
    }
    cout << g.minDistance(1, n);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    //t = 1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        ////cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
