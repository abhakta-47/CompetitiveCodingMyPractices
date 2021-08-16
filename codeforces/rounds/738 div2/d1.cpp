#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

class GroupedGraph {
  public:
    ll nSec, nNode;
    vector<vector<ll>> edges;
    map<ll, vector<ll>> sec2node;
    map<ll, ll> node2sec;
    GroupedGraph(ll n) {
        nNode = n;
        nSec = 0;
        edges.resize(n, {});
        // cout << " ." << n << " " << edges.size() << " : ";
    }
    bool addEdge(ll x, ll y) {
        // clog << x << " " << y << ": ";
        // edges[0].push_back(0);
        if (!diffGrp(x, y))
            return false;
        edges[x].pb(y);
        edges[y].pb(x);

        if (node2sec.find(x) == node2sec.end() &&
            node2sec.find(y) == node2sec.end()) {
            // clog << "0";
            ++nSec;
            node2sec[x] = nSec;
            node2sec[y] = nSec;
            sec2node[nSec].push_back(x);
            sec2node[nSec].push_back(y);
        } else if (node2sec.find(x) != node2sec.end() &&
                   node2sec.find(y) != node2sec.end()) {
            // clog << "1";
            ll sec1 = node2sec[x], sec2 = node2sec[y];
            for (auto node : sec2node[sec2]) {
                node2sec[node] = sec1;
                sec2node[sec1].push_back(node);
            }
            sec2node.erase(sec2);
        } else if (node2sec.find(x) != node2sec.end()) {
            // clog << "2";
            ll sec = node2sec[x];
            // clog << " " << sec;
            node2sec[y] = sec;
            sec2node[sec].push_back(y);
        } else {
            // clog << "3";
            ll sec = node2sec[y];
            node2sec[x] = sec;
            sec2node[sec].push_back(x);
        }
        // clog << "\n";
        return true;
    }
    bool diffGrp(ll x, ll y) {
        // clog << x << "," << y << " : ";
        if (node2sec.find(x) == node2sec.end() ||
            node2sec.find(y) == node2sec.end()) {
            // clog << y << "\n";
            return true;
        }
        // clog << node2sec[x] << ":" << node2sec[y]
        // << (node2sec[x] != node2sec[y]) << "\n";
        return (node2sec[x] != node2sec[y]);
    }
    void print() {
        for (auto is : sec2node) {
            clog << is.first << "->";
            for (auto iv : is.second)
                clog << iv << "=" << node2sec[iv] << ", ";
        }
        clog << "\n";
    }
};

void sol() {
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    GroupedGraph g1(n), g2(n);
    ll x, y;
    for (int i = 0; i < m1; i++) {
        cin >> x >> y;
        g1.addEdge(x - 1, y - 1);
    }
    for (int i = 0; i < m2; i++) {
        cin >> x >> y;
        g2.addEdge(x - 1, y - 1);
    }
    // g1.print();
    // g2.print();
    vector<pair<ll, ll>> ans;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (g1.diffGrp(i, j) && g2.diffGrp(i, j)) {
                ans.push_back({i, j});
                g1.addEdge(i, j);
                g2.addEdge(i, j);
                // g1.print();
                // g2.print();
            }
            // clog << "\n";
        }
    cout << ans.size() << "\n";
    for (auto ia : ans)
        cout << ia.first + 1 << " " << ia.second + 1 << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog << "\n";
        cout << "\n";
    }
}
