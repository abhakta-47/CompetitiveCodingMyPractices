#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> iPair;
struct Graph
{
    int V; // No. of vertices

    //graph containing vector
    vector<vector<int>> adj;
    vector<pair<int, iPair>> edges;
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
        // //cout << "joining " << v << " " << w << " ";
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // for non-direcrted graph
        // //cout << adj[v].size() << " " << adj[v][adj[v].size() - 1] << " " << adj[w].size() << " " << adj[w][adj[w].size() - 1] << "\n";
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
        addEdge(u, v);
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

                    // if (adj[s][i] == e)
                    //     return node_distants[e];
                }
                // cout << node_distants[adj[s][i]] << " ";
            }
            // cout << "\n";
        }

        int k = 0;
        for (i = 1; i < node_distants.size(); i++)
        {
            // cout << i << "=" << node_distants[i] << "\n";
            if (node_distants[i] == e)
                ++k;
        }

        return k;
    }

    int kruskalMST();
};

int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjointSets ds(V);

    // Iterate through all sorted edges
    vector<pair<int, iPair>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            // cout << u << " - " << v << endl;

            // Update MST weight
            mst_wt += it->first;

            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }
    return mst_wt;
}