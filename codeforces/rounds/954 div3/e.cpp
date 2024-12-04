#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, k, ans = 0;

ll get_diff(vector<ll> &a, ll idx) {
    if (idx == 0)
        return a[1] - a[0];
    if (idx == a.size() - 1)
        return a[a.size() - 1] - a[a.size() - 2];
    return a[idx + 1] - a[idx - 1];
}

ll min_sum_util(vector<ll> &a, ll idx) {
    ll ans = 0;
    loop(i, 0, a.size()) {
        if (i + 1 >= n)
            break;
        if (i == idx)
            continue;
        if (i + 1 == idx) {
            ans += (a[i + 2] - a[i]) / k;
            continue;
        }
        ans += (a[i + 1] - a[i]) / k;
        ++i;
    }
    return ans;
}

ll min_sum(vector<ll> &a) {
    sort(a.begin(), a.end());
    loop(i, 0, a.size()) clog << a[i] << ".";
    clog << " :: ";
    if (a.size() == 1)
        return 0;
    ll ans = 0;

    if (a.size() % 2) {
        ans = min_sum_util(a, 0);
        loop(i, 1, a.size()) { ans = min(ans, min_sum_util(a, i)); }

    } else {
        for (int i = 1; i < a.size(); i += 2)
            ans += (a[i] - a[i - 1]) / k;
    }
    clog << " := " << ans << "\n";
    return ans;
}

void sol() {
    cin >> n >> k;
    ans = 0;
    vector<ll> a(n);
    loop(i, 0, n) cin >> a[i];

    map<ll, vector<ll>> m;

    loop(i, 0, n) m[a[i] % k].pb(a[i]);

    loop(i, 0, n) clog << a[i] << " ";
    clog << ":" << k;
    clog << "::\n";

    if (n % 2 == 0) {
        for (auto i : m) {
            if (i.second.size() % 2 != 0) {
                cout << "-1";
                return;
            }
        }
    } else {
        bool flg = false;
        for (auto i : m) {
            if (i.second.size() % 2 != 0) {
                if (flg == false)
                    flg = true;
                else {
                    cout << "-1";
                    return;
                }
            }
        }
    }

    ll ans = 0;
    for (auto i : m) {
        ans += min_sum(i.second);
    }
    clog << ":= ";
    clog << ans;
    clog << "\n";
    cout << ans;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clog.tie(NULL);

    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        clog << "Case #" << i + 1 << ": \n";
        sol();
        clog << "\n";
        cout << "\n";
    }
}
