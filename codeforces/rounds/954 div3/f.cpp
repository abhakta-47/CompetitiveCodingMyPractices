#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(n);
    vector<ll> freq_edges(n, 0);
    ll u, v;
    loop(i, 0, m) {
        cin >> u >> v;
        --u;
        --v;
        edges[u].pb(v);
        edges[v].pb(u);
        ++freq_edges[u];
        ++freq_edges[v];
    }
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
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
