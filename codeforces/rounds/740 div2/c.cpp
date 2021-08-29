#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, x;
    cin >> n;
    vector<ll> caves[n];
    for (ll i = 0; i < n; i++) {
        ll j;
        cin >> j;
        while (j--) {
            cin >> x;
            caves[i].push_back(x);
        }
    }
    // for (auto cave : caves) {
    //     for (auto monster : cave)
    //         cout << monster << ", ";
    //     cout << "\n";
    // }
    pair<ll, ll> powers[n];
    ll t;
    for (ll i = 0; i < n; i++) {
        t = 0;
        for (ll j = 0; j < caves[i].size(); j++) {
            // cout << caves[i][j] - j + 1 << " ";
            if (caves[i][j] > j)
                t = max(t, caves[i][j] - j);
        }
        // cout << ":" << t << ", ";
        powers[i] = {t, caves[i].size()};
    }
    sort(powers, powers + n);
    ll ans = (ll)0;
    x = (ll)0; // powers[0], x = caves[0].size();
    for (ll i = 0; i < n; i++) {
        // cout << powers[i].first << "-" << x << "=" << powers[i].first - x
        //      << ", ";
        ans = max(ans, (powers[i].first - x));
        x += powers[i].second;
    }
    cout << ans + (ll)1;
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
