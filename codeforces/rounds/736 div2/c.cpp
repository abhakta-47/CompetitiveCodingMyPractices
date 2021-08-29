#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

class Nobles {
  public:
    ll n, m;
    set<ll> dead;
    vector<set<ll>> edges;
    Nobles(ll n, ll m) : n(n), m(m) { edges.resize(n); }
    bool isSurvivor(ll p) {
        if (edges[p].empty())
            return true;
        ll t = *(--edges[p].end());
        return (t < p);
    }
    bool setState(ll p) {
        if (isSurvivor(p))
            dead.erase(p);
        else
            dead.insert(p);
    }
    void addFriend(ll u, ll v) {
        edges[u].insert(v);
        edges[v].insert(u);
        setState(u);
        setState(v);
    }
    void removeFriend(ll u, ll v) {
        edges[u].erase(v);
        edges[v].erase(u);
        setState(u);
        setState(v);
    }
    ll survivors() { return (n - dead.size()); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, u, v;
    cin >> n >> m;
    Nobles friends(n, m);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        friends.addFriend(u - 1, v - 1);
    }
    ll q, x;
    cin >> q;
    while (q--) {
        cin >> x;
        switch (x) {
        case 1:
            cin >> u >> v;
            friends.addFriend(u - 1, v - 1);
            break;

        case 2:
            cin >> u >> v;
            friends.removeFriend(u - 1, v - 1);
            break;

        default:
            cout << friends.survivors() << "\n";
        }
    }
}
