#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    int x;
    stack<int> s, t;
    for (int i = 0; i < n; i++) {
        cin >> x;
        while (!s.empty() && s.top() > x) {
            if ((s.top() + x) % 2) {
                t.push(s.top());
                s.pop();
            } else {
                cout << "NO";
                return;
            }
        }
        s.push(x);
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
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
