// https://www.geeksforgeeks.org/count-possible-paths-two-vertices/

#include <bits/stdc++.h>

using namespace std;

class Graph {
  public:
    int V; // No. of vertices

    // graph containing vector
    vector<vector<int>> adj;
    vector<bool> visited;

    Graph(int V) // Constructor
    {
        this->V = V;
        adj.resize(V + 1);
        // node_distants.resize(V + 1);
        visited.resize(V + 1, false);
    }

    void addEdge(int v, int w) {
        // //cout << "joining " << v << " " << w << " ";
        adj[v].push_back(w); // Add w to v’s list.
        // adj[w].push_back(v); // for non-direcrted graph
        // //cout << adj[v].size() << " " << adj[v][adj[v].size() - 1] << " " <<
        // adj[w].size() << " " << adj[w][adj[w].size() - 1] << "\n";
    }

    void visitReset() { // reset visit array to zero
        for (int i = 0; i <= V; i++)
            visited[i] = false;
    }

    // A recursive function used by DFS
    int DFSUtil(int v, int dest, int *dp) {
        if (v == dest)
            return 1;
        // Mark the current node as visited and
        // print it
        visited[v] = true;
        // cout << v << " ? " << visited[v] << " ";
        // Recur for all the vertices adjacent
        // to this vertex
        int i;
        int ans = 0;
        cout << v << "-> ";
        for (auto nei : adj[v]) {
            // cout << v << " -> " << nei << "\n";
            // if (nei == dest)
            // ans++;
            if (!visited[nei])
                dp[nei] = DFSUtil(nei, dest, dp);
            dp[v] += dp[nei];
        }
        // for (auto nei : adj[v]) {
        // cout << nei << "-" << dp[nei] << ",";
        // ans += dp[nei];
        // }
        // dp[v] = ans;
        cout << v << "=" << dp[v] << "; ";
        return dp[v];
    }

    int count_paths(int src, int dest) {
        visitReset();
        int dp[V] = {0};
        dp[dest] = 1;
        return DFSUtil(src, dest, dp);
    }

    // int count_paths(int src, int dest) {
    //     visitReset();
    //     stack<int> s;
    //     s.push(dest);
    //     int dp[V] = {0};
    //     while (!s.empty()) {
    //         int t = s.top();
    //         s.pop();
    //         cout << t << "->";
    //         for (auto nei : adj[t]) {
    //             dp[nei]++;
    //             if (!visited[nei])
    //                 s.push(nei);
    //         }
    //         visited[t] = true;
    //     }
    //     // cout << dp[src];
    //     return dp[src];
    // }

    // void DFS(int v) {
    //     visitReset();
    //     DFSUtil(v);
    // }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    cout << g.count_paths(0, 4);
}