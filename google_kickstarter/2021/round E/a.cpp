#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

bool comp(pair<char, stack<int>> &x, pair<char, stack<int>> &y) {
    return (x.second.size() >= y.second.size());
}

void sol() {
    string s;
    cin >> s;
    string back = s;
    ll n = s.length();

    map<char, stack<int>> m;
    vector<pair<char, stack<int>>> v;
    for (int i = 0; i < n; i++)
        m[s[i]].push(i);

    for (auto im : m) {
        v.push_back({im.first, im.second});
    }
    sort(v.begin(), v.end(), comp);
    for (auto iv : v) {
        stack<int> &s1 = m[iv.first];
        // cout << iv.first << s1.size() << " ";
        for (auto jv : v) {
            if (iv.first != jv.first) {
                stack<int> &s2 = m[jv.first];
                // cout << ":" << jv.first << jv.second.size() << "->";
                while (!s1.empty() && !s2.empty()) {
                    swap(s[s1.top()], s[s2.top()]);
                    // cout << s1.size();
                    s1.pop();
                    // cout << s1.size();
                    // cout << s2.size();
                    s2.pop();
                    // cout << s2.size();
                    // cout << s << ", ";
                }
                // cout << s1.size();
                // cout << m[iv.first].size();
            }
        }
        // cout << s1.size() << "\n";
    }
    cout << s << " " << back << " ";
    for (int i = 0; i < n; i++)
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
