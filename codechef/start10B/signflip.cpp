#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, k, x;
    cin >> n >> k;
    vector<ll> pos, neg;
    loop(i, 0, n) {
        cin >> x;
        if (0 <= x)
            pos.push_back(x);
        else
            neg.push_back(x);
    }
    sort(neg.begin(), neg.end());
    ll ans = 0;
    for (int i = 0; i < k && i < neg.size(); i++)
        ans += (-1) * neg[i];
    for (auto ip : pos)
        ans += ip;
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
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
