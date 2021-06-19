#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
struct DisjointSets
{
    int *parent, *rnk;
    int n;

    // Constructor.
    DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            //every element is parent of itself
            parent[i] = i;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path 
		from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        /* Make tree with smaller height 
		a subtree of the other tree */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

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

    int kruskalMST()
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
};

class Graph {
    int V; // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
    int k;
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    vector<int> connectedComponents();
};
 
// Method to print connected components in an
// undirected graph
vector<int> Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
    vector<int>nVectexComponent;
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            k=0;
            DFSUtil(v, visited);
            nVectexComponent.push_back(k);
            cout << "-"<<k<< "\n";
        }
    }
    delete[] visited;
    return nVectexComponent;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    ++k;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph() { delete[] adj; }
 
// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    Graph g(n);
    for(auto iv:cities){
        // for(auto iv2:iv)
        cout<<iv[0]<<","<<iv[1]<<"\n";
        g.addEdge(iv[0]-1,iv[1]-1);
            // cout<<iv2<<", ";
        // cout<<"\n";
    }
    vector<int>nVectexComponent= g.connectedComponents();
    long long  ans=0;
    for(auto n : nVectexComponent)
        ans+= (long long)( c_lib<c_road ? n*c_lib : c_lib+(n-1)*c_road );
    return ans;
}