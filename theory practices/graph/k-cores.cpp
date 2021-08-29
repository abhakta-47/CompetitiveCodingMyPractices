#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

class Graph {
  public:
    int V; // No. of vertices

    // graph containing vector
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> node_distants;

    Graph(int V) // Constructor
    {
        this->V = V;
        adj.resize(V + 1);
        node_distants.resize(V + 1);
        visited.resize(V + 1, false);
    }

    void addEdge(int v, int w) {
        // //cout << "joining " << v << " " << w << " ";
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // for non-direcrted graph
        // //cout << adj[v].size() << " " << adj[v][adj[v].size() - 1] << " " <<
        // adj[w].size() << " " << adj[w][adj[w].size() - 1] << "\n";
    }

    // A recursive function used by DFS
    void DFSUtil(int v) {
        // Mark the current node as visited and
        // print it
        visited[v] = true;
        // //cout << v << " ? " << visited[v] << " ";
        // Recur for all the vertices adjacent
        // to this vertex
        int i;
        for (i = 0; i < adj[v].size(); ++i) {
            // //cout << v << " -> " << adj[v][i] << "\n";
            if (!visited[adj[v][i]])
                DFSUtil(adj[v][i]);
        }
    }

    void visitReset() { // reset visit array to zero
        for (int i = 0; i <= V; i++)
            visited[i] = false;
    }

    void DFS(int v) {
        visitReset();
        DFSUtil(v);
    }
    void recurRemove(int k, int p, vector<bool> &isRemoved) {
        int curNei = 0;
        for (auto nei : adj[p])
            if (!isRemoved[nei])
                ++curNei;
        // clog << p << "->" << curNei << ", ";
        if (curNei < k) {
            isRemoved[p] = true;
            for (auto nei : adj[p])
                if (!isRemoved[nei])
                    recurRemove(k, nei, isRemoved);
        }
    }
    void kCore(int k) {
        vector<bool> isRemoved(V, false);
        for (int i = 0; i < V; i++)
            if (!isRemoved[i])
                recurRemove(k, i, isRemoved);
        for (int i = 0; i < V; i++) {
            if (isRemoved[i])
                continue;
            cout << i << " -> ";
            for (auto nei : adj[i])
                if (!isRemoved[nei])
                    cout << nei << ", ";
            cout << "\n";
        }
    }
};

int main() {
    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.kCore(k);

    cout << endl << endl;

    Graph g2(13);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(1, 6);
    g2.addEdge(2, 7);
    g2.addEdge(2, 8);
    g2.addEdge(2, 9);
    g2.addEdge(3, 10);
    g2.addEdge(3, 11);
    g2.addEdge(3, 12);
    g2.kCore(k);
}
