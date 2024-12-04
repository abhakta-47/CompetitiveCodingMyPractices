#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    if (n < 5) {
        cout << -1;
        return;
    }

    vector<ll> odds, evens;
    loop(i, 1, n + 1) {
        if (i % 2)
            odds.pb(i);
        else
            evens.pb(i);
    }

    swap(evens[0], evens[1]);
    swap(odds[2], odds[odds.size() - 1]);

    for (auto i : odds)
        cout << i << " ";
    for (auto i : evens)
        cout << i << " ";

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
