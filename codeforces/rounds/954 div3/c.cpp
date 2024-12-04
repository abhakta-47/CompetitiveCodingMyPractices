#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<ll> a;
    ll temp;
    loop(i, 0, m) {
        cin >> temp;
        a.insert(temp);
    }
    vector<char> c(m);
    loop(i, 0, m) cin >> c[i];

    sort(c.begin(), c.end());

    // loop(i, 0, a.size()) { s[a[i]] = c[i]; }
    ll curidx = 0;
    for (auto i : a) {
        // cout << i << "." << c[curidx] << " ";
        s[i - 1] = c[curidx++];
    }

    cout << s;

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
