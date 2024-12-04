#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n) cin >> b[i];
    vector<ll> c(m);
    loop(i, 0, m) cin >> c[i];

    map<ll, ll> mp;
    loop(i, 0, n) {
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = b[i];
        else
            mp[a[i]] = max(mp[a[i]], b[i]);
    }
    map<ll, ll> dp;
    for (auto ia : mp) {
        clog << ia.first << " " << ia.second << ":: ";
        dp[ia.first] = 0;
        for (auto ja : mp) {
            if (ja.first > ia.second)
                break;
            clog << ja.first << "." << dp[ja.first] << "";
            dp[ia.first] = max(dp[ia.first], dp[ja.first]);
        }
        dp[ia.first]++;
        clog << " :: " << ia.first << "->" << dp[ia.first] << "\n";
    }
    ll ans = 0, cur;
    loop(i, 0, m) {
        auto cur_ptr = dp.lower_bound(c[i]);
        if (cur_ptr->first != c[i] && cur_ptr == dp.begin())
            continue;

        cur = (--dp.lower_bound(c[i]))->first;
        clog << c[i] << "->" << cur << "=";
        cur = (c[i] - cur) + dp[cur];
        clog << cur << "\n";
        ans += cur;
    }
    clog << ans * 2;
    cout << ans * 2;
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
        clog << "\nCase #" << i + 1 << ": \n";
        sol();
        cout << "\n";
    }
}