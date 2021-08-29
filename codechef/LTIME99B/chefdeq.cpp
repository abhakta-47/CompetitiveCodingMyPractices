#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n;
void valid(ll x1, ll x2, ll &maxi) {
    if (x1 > x2)
        swap(x1, x2);
    ++x1;
    x2 = n - x2 - 1;
    // cout << "(" << x1 << "," << x2 << ")" << (x1 & (~x2));
    if (x1 & (~x2))
        return;
    ll cnt = 0;
    while (x2) {
        if (x2 % 2)
            ++cnt;
        x2 = x2 / 2;
    }
    // cout << " = " << cnt;
    maxi = min(maxi, cnt);
}

void sol() {
    ll m;
    cin >> n >> m;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    ll pre[n];
    pre[0] = a[0] % m;
    // cout << pre[0] << " ";
    map<ll, set<ll>> mods;
    mods[pre[0]].insert(0);
    for (int i = 1; i < n; i++) {
        pre[i] = (pre[i - 1] + a[i]) % m;
        mods[pre[i]].insert(i);
        // cout << pre[i] << " ";
    }
    // cout << "\n";
    mods[0].insert(-1);
    ll mod, maxi = n + 1;
    set<ll> s;
    for (auto im : mods) {
        mod = im.first;
        // cout << mod << "-> ";
        s = im.second;
        for (auto s1 = s.begin(); s1 != s.end(); s1++) {
            // cout << *s1 << ": ";
            for (auto s2 = s1; s2 != s.end(); s2++) {
                if (s1 == s2)
                    continue;
                // cout << *s2;
                valid(*s1, *s2, maxi);
                // cout << ", ";
            }
            // cout << "\t";
        }
        // cout << "\n";
    }
    if (maxi == n + 1)
        cout << -1;
    else
        cout << maxi;
    // cout << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
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
