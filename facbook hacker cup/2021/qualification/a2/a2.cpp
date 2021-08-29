#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

string s;
ll k;

class Graph {

  public:
    map<char, set<char>> adj;
    map<char, map<char, ll>> allDistances;
    Graph(string s) {}
    void addEdge(char c, char d) { adj[c].insert(d); }
    void minDistance(char start) {
        // map<char, ll> &distances = allDistances[start];
        bool visited[adj.size()] = {0};
        queue<char> q;
        q.push(start);
        char cur;
        while (!q.empty()) {
            cur = q.front();
            // cout << cur << "->";
            visited[cur - 'A'] = true;
            q.pop();
            for (auto iadj : adj[cur]) {
                if (allDistances[start].find(iadj) == allDistances[start].end())
                    allDistances[start][iadj] = allDistances[start][cur] + 1;
                else
                    allDistances[start][iadj] =
                        min(allDistances[start][iadj],
                            allDistances[start][cur] + 1);
                if (!visited[iadj - 'A'])
                    q.push(iadj);
            }
            // cout << "\n";
        }
    }
    void getAllDistances() {
        for (auto is : adj)
            minDistance(is.first);
    }
};

void sol() {
    cin >> s;
    // cout << s;
    cin >> k;
    char c, d;
    Graph g(s);
    loop(i, 0, k) {
        cin >> c >> d;
        g.addEdge(c, d);
    }

    // for (auto node : g.adj) {
    // cout </< node.first << "->";
    // for (auto iadj : node.second)
    // cout << iadj << ", ";
    // cout << "\n";
    // }
    g.getAllDistances();
    // for (auto node : g.allDistances) {
    //     cout << node.first << " -> ";
    //     for (auto nei : node.second)
    //         cout << nei.first << "=" << nei.second << ", ";
    //     cout << "\n";
    // }

    map<char, ll> freq;
    for (auto is : s)
        freq[is]++;

    ll cost = 0, totalCost, ans = LONG_LONG_MAX;
    for (int i = 0; i < 26; i++) {
        char is = 'A' + i;
        // cout << "\nto " << is << " : ";
        cost = 0;
        for (auto [js, tmp] : freq) {
            if (is == js)
                continue;
            if (g.allDistances[js].find(is) == g.allDistances[js].end()) {
                cost = -1;
                break;
            }
            // cout << freq[js] << "*" << g.allDistances[js][is] << "+";
            cost += freq[js] * g.allDistances[js][is];
        }
        if (cost != -1) {
            // cout << " =" << cost;
            ans = min(ans, cost);
        }
    }
    // cout << " ::: ";
    if (ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << ans;
    // cout << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
