#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

void sol() {
    string s;
    cin >> s;
    string back = s;
    ll l = s.length();
    map<char, int> m;
    for (int i = 0; i < l; i++) {
        // cout << s[i] << back[i] << "->";
        if (s[i] != back[i])
            continue;
        for (int j = 0; j < l; j++) {
            // cout << s[j] << back[j];
            if (s[j] != back[i] && s[i] != back[j]) {
                // cout << "*";
                swap(s[i], s[j]);
                break;
            }
            // cout << ",";
        }
        // cout << "\n";
    }
    for (int i = 0; i < l; i++)
        if (s[i] == back[i]) {
            cout << "IMPOSSIBLE";
            return;
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
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
