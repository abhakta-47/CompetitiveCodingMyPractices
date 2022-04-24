#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, ans;
vector<ll> funfactors;
vector<ll> dp;
vector<vector<ll>> chain;

ll dfs(ll node) {

    if (dp[node] != 0)
        return dp[node];

    if (chain[node].size() == 0)
        return funfactors[node];

    vector<ll> values;
    for (auto child : chain[node])
        values.push_back(dfs(child));
    sort(values.begin(), values.end());
    for (auto value : values)
        ans += value;
    ans -= values[0];
    // cout << node << "-" << ans << ", ";
    return max(values[0], funfactors[node]);
}

void sol() {
    cin >> n;
    ans = 0;
    funfactors.clear();
    funfactors.reserve(n);
    dp.clear();
    dp.resize(n, 0);
    chain.clear();
    chain.resize(n, vector<ll>());

    loop(i, 0, n) cin >> funfactors[i];
    ll parent;
    vector<ll> chainends;
    loop(i, 0, n) {
        cin >> parent;
        if (parent == 0) {
            chainends.push_back(i);
            continue;
        }
        chain[parent - 1].push_back(i);
    }
    for (auto chainend : chainends)
        ans += dfs(chainend);
    cout << ans;
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
        cout << "\n";
    }
}
