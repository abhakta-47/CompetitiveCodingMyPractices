#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, t;
    cin >> n;
    vector<ll> odds, evens;
    for (ll i = 0; i < n; i++) {
        cin >> t;
        if (t % 2)
            odds.push_back(t);
        else
            evens.push_back(t);
    }
    ll no = odds.size(), ne = evens.size();
    if (no == 0 || no == 1) {
        cout << "-1";
    } else if (ne == 0) {
        if (no % 2) {
            cout << "-1";
        } else {
            for (int i = 0; i < ne; i++)
                cout << evens[i] << " ";
            for (int i = 0; i < no; i++)
                cout << odds[i] << " ";
        }
    } else {
        for (int i = 0; i < ne - 1; i++)
            cout << evens[i] << " ";
        if (no % 2) {
            cout << odds[0] << " ";
            cout << evens[ne - 1] << " ";
        } else {
            cout << evens[ne - 1] << " ";
            cout << odds[0] << " ";
        }
        for (int i = 1; i < no; i++)
            cout << odds[i] << " ";
    }
    // cout << "\n";
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
