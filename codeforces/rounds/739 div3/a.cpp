#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

vector<ll> v;

bool check(ll x) {
    string s = to_string(x);
    return (s[s.length() - 1] == '3');
}

void prev() {
    ll i = 1;
    v.clear();
    while (v.size() <= 1001) {
        if (!(i % 3 == 0 || check(i)))
            v.pb(i);
        i++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prev();
    // for (auto iv : v)
    //     cout << iv << ", ";
    int t, x;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x;
        cout << v[x - 1] << "\n";
    }
}
