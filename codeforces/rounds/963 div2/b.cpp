#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, x;
    cin >> n;
    vector<ll> odds, evens;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0)
            evens.pb(x);
        else
            odds.pb(x);
    }

    if (evens.size() == n || odds.size() == n) {
        cout << 0;
        return;
    }

    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    if (odds[odds.size() - 1] > evens[evens.size() - 1]) {
        cout << evens.size();
        return;
    }
    ll cur_odd = odds[odds.size() - 1];
    for (int i = 0; i < evens.size() && evens[i] < cur_odd; i++) {
        // clog << i << " " << evens[i] << " " << cur_odd << "\n";
        cur_odd += evens[i];
    }
    if (cur_odd >= evens[evens.size() - 1])
        cout << evens.size();
    else
        cout << evens.size() + 1;
    // clog << "\n";
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
