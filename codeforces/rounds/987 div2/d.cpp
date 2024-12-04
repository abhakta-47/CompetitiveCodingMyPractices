#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)
#define looprev(i, x, n) for (int i = x; i >= n; i--)

bool customOp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    // cout << ".{" << a.first << "," << a.second << "}{" << b.first << ","
    //  << b.second << "} " << (a.first <= b.first) << "; ";
    return a.first < b.first;
}
ll n;
vector<ll> a(n);
vector<ll> ans(n);
vector<ll> min_2_right(n);
vector<ll> max_2_left(n);

ll recur = 0;
ll dp(ll pos, set<ll> &actives) {

    clog << pos << "->";

    if (recur++ > 100)
        return 0;

    if (ans[pos] != -1) {
        clog << pos << "=" << ans[pos] << "; ";
        return ans[pos];
    }

    actives.insert(pos);

    if (actives.find(pos) != actives.end()) {
        ans[pos] = max(a[max_2_left[pos]], ans[min_2_right[pos]]);
        clog << pos << "=" << ans[pos] << "; ";
        return ans[pos];
    }

    ll x = max_2_left[pos] == pos ? a[pos] : dp(max_2_left[pos], actives);
    ll y = min_2_right[pos] == pos ? a[pos] : dp(min_2_right[pos], actives);

    ans[pos] = max(x, y);
    clog << pos << "=" << ans[pos] << "; ";

    return ans[pos];
}

void sol() {
    a.clear();
    ans.clear();
    max_2_left.clear();
    min_2_right.clear();

    recur = 0;

    ll n;
    cin >> n;

    a.resize(n);
    ans.resize(n, -1);
    max_2_left.resize(n);
    min_2_right.resize(n);

    loop(i, 0, n) cin >> a[i];

    set<pair<ll, ll>> s;
    looprev(i, n - 1, 0) {
        s.insert({a[i], i});
        auto it = s.lower_bound({a[i], i});
        ll val = it->first;
        ll idx = it->second;
        if (val == a[i] && idx == i && it != s.begin()) {
            --it;
            val = it->first;
            idx = it->second;
        }

        min_2_right[i] = idx;
    }
    loop(i, 0, n) clog << "[" << min_2_right[i] << "]=" << a[min_2_right[i]]
                       << "; ";
    clog << "\n";
    s.clear();
    ll x = 0;
    loop(i, 0, n) {
        if (a[i] > a[x])
            x = i;
        ll idx = x;
        ll val = a[idx];
        clog << "[" << idx << "]=" << val << "; ";
        max_2_left[i] = idx;
    }
    looprev(i, n - 1, 0) {
        set<ll> actives;
        dp(i, actives);
    }
    loop(i, 0, n) cout << ans[i] << " ";
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
        clog << "\n";
        cout << "\n";
    }
}
