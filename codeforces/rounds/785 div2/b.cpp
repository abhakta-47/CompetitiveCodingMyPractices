#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string s;
    cin >> s;

    ll n = s.length();

    set<char> setc;
    for (auto ic : s)
        setc.insert(ic);
    ll nc = setc.size();

    // cout << s << ":" << nc << " ";

    set<string> sets;
    loop(i, 0, (n - nc + 1)) sets.insert(s.substr(i, nc));

    for (auto is : sets) {
        // cout << is << ", ";
        setc.clear();
        for (auto ic : is)
            setc.insert(ic);
        if (setc.size() != nc) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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
