#include <bits/stdc++.h>

using namespace std;

#define ll int
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

vector<vector<ll>> edges;
vector<bool> visited;
vector<ll> amnt;

ll dfs(ll node) {
    visited[node] = true;
    // cout<<
    ll total = amnt[node];
    for (auto child : edges[node])
        if (!visited[child])
            total += dfs(child);
    return total;
}

void sol() {
    ll n;
    cin >> n;
    amnt.clear();
    amnt.resize(n);
    loop(i, 0, n) cin >> amnt[i];
    ll p;
    cin >> p;
    // cout << p << "\n";
    edges.clear();
    edges.resize(n, vector<ll>());
    ll u, v;
    loop(i, 0, p) {
        cin >> u >> v;
        // cout << u << " " << v << "\n";
        if (u < v)
            edges[u - 1].push_back(v - 1);
        else
            edges[v - 1].push_back(u - 1);
    }
    visited.clear();
    visited.resize(n, false);
    ll ans = 0;
    loop(i, 0, n) {
        if (!visited[i])
            ans = max(ans, dfs(i));
    }
    cout << ans;
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
