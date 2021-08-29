#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

vector<ll> pow2s;

void prev() {
    for (ll x = 1; x <= 2e18; x *= 2)
        pow2s.push_back(x);
}

ll diff(string given, string target) {
    ll ig = 0, it = 0;
    for (int ig = 0; ig < given.length() && it < target.length(); ig++)
        if (given[ig] == target[it])
            ++it;
    return given.length() + target.length() - 2 * (it);
}

ll diff(ll x, ll y) { return diff(to_string(x), to_string(y)); }

void sol() {
    ll n;
    cin >> n;
    ll ans = 100, t;
    for (auto ip : pow2s) {
        t = diff(n, ip);
        // cout << n << " " << ip << " = " << t << "\n";
        ans = min(ans, t);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prev();
    // for (auto ix : pow2s)
    //     cout << ix << ",";
    // return 1;

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
