// https: //www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/so-np-c559f406/editorial/
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
        visited.resize(V + 1, false);
    }
    // function to add an edge to graph
    void addEdge(int v, int w)
    {
        // //cout << "joining " << v << " " << w << " ";
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // for non-direcrted graph
        // //cout << adj[v].size() << " " << adj[v][adj[v].size() - 1] << " " << adj[w].size() << " " << adj[w][adj[w].size() - 1] << "\n";
    }
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v)
    {

        // for (int i = 1; i <= V; i++)
        // {
        //     // //cout << i << " -> ";
        //     for (int j = 0; j < adj[i].size(); j++)
        //     {
        //         //cout << adj[i][j] << " ";
        //     }
        //     // //cout << "\n";
        // }

        // Mark all the vertices as not visitedx
        // bool visited[V];

        // // Call the recursive helper function
        // // to print DFS traversal
        DFSUtil(v);
    }

    int nComponents()
    {
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
};

int func()
{
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    int i, v, w;
    for (i = 0; i < m; i++)
    {
        cin >> v >> w;
        g.addEdge(v, w);
    }
    int nc = g.nComponents();
    cout << ((nc > k) ? -1 : m - n + k);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    t = 1;
    //cin>>t;
    for (i = 0; i < t; i++)
    {
        ////cout<<"Case #"<<i+1<<": ";
        func();
        //cout << "\n";
    }
}
