#include <bits/stdc++.h>

using namespace std;

#define ll int
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, m, q;
vector<bool> visited;
vector<bool> frozen;
unordered_set<int> frozens;
vector<vector<ll>> edges;

void reset() {
    visited.clear();
    edges.clear();
    frozen.clear();
    frozens.clear();
    visited.resize(n, false);
    frozen.resize(n, false);
    edges.resize(n, vector<ll>());
}

void isFrozen(int node) {
    if (frozen[node - 1])
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";
}

void dfs(int time, bool starter) {
    unordered_set<int> nxtnodes;
    while (true) {
        for (auto node : frozens) {
            if (visited[node])
                continue;
            frozen[node] = true;
            visited[node] = true;
            nxtnodes.insert(node);
        }
        --time;
        if (time < 0)
            break;
        frozens = nxtnodes;
    }
}

void sol() {
    cin >> n >> m >> q;
    reset();
    ll u, v;
    loop(i, 0, m) {
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }
    ll prevu = -1, prevv = 0;
    pair<ll, ll> queries[q];
    loop(i, 0, q) {
        cin >> u >> v;
        queries[i] = {u, v};
    }
    loop(i, 0, q) {
        u = queries[i].first;
        v = queries[i].second;
        switch (u) {
        case 1:
            frozen[v - 1] = true;
            frozens.insert(v - 1);
            break;
        case 2:
            if (i != q - 1 && queries[i + 1].first == 2) {
                queries[i + 1].second += v;
                break;
            }
            visited.clear();
            visited.resize(n, false);
            dfs(v, true);
            // loop(i, 0, n) {
            //     if (frozen[i] && !visited[i]) {
            //         dfs(v, true);
            //         visited[i] = true;
            //     }
            // }
            break;
        case 3:
            isFrozen(v);
            break;
        default:
            break;
        }
        prevu = u;

        // loop(i, 0, n) {
        //     cout << i << ":" << frozen[i] << "-> ";
        //     for (auto neig : edges[i])
        //         cout << neig << ":" << frozen[neig] << ", ";
        //     cout << "\n";
        // }
        // cout << "\n";
    }
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
        // clog<<"\n";
        // cout << "\n";
    }
}
