#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)
#define MOD 998244353

ll n;
vector<set<ll>> edges;
unordered_map<ll, vector<ll>> val_poss;
unordered_map<ll, vector<ll>> factor_city;

void preprocess_factors(ll max_num) {
    factor_city.clear();
    for (ll i = 1; i <= max_num; i++) {
        for (ll j = i; j <= max_num; j += i) {
            for (auto k : val_poss[j])
                factor_city[i].pb(k);
        }
    }
}

ll dfs(ll node) {
    ll ans = 0;
    if (node == n - 1)
        return 1;
    for (auto i : edges[node]) {
        ans = (ans + dfs(i)) % MOD;
    }
    return ans;
}

void sol() {

    edges.clear();
    val_poss.clear();
    factor_city.clear();

    cin >> n;

    edges.resize(n);
    vector<ll> a(n);
    ll max_num = 0;
    loop(i, 0, n) {
        cin >> a[i];
        val_poss[a[i]].pb(i);
        max_num = max(max_num, a[i]);
    }

    preprocess_factors(max_num);
    factor_city.erase(1);

    for (auto i : factor_city) {
        clog << i.first << ": ";
        sort(i.second.begin(), i.second.end());
        for (auto j : i.second) {
            clog << j << " ";
        }
        clog << "\n";
    }

    for (auto ia : factor_city)
        for (int i = 0; i < ia.second.size() - 1; i++)
            for (int j = i + 1; j < ia.second.size(); j++) {
                if (ia.second[i] < ia.second[j])
                    edges[ia.second[i]].insert(ia.second[j]);
                if (ia.second[i] > ia.second[j])
                    edges[ia.second[j]].insert(ia.second[i]);
            }

    loop(i, 0, n) {
        clog << i << "-> ";
        for (auto j : edges[i])
            clog << j << " ";
        clog << "\n";
    }

    cout << dfs(0);

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
        sol();
        cout << "\n";
    }
}