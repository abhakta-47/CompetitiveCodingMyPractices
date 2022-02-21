#include <bits/stdc++.h>

using namespace std;

#define ll int
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void print(stack<pair<ll, ll>> &s, stack<pair<ll, ll>> &t) {
    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }
    while (!t.empty()) {
        cout << "{" << t.top().first << " " << t.top().second << "} ";
        s.push(t.top());
        t.pop();
    }
    cout << ",  ";
}

void sol() {
    ll n;
    cin >> n;

    ll a[n + 1] = {0}, x, max_el;
    pair<ll, ll> top;
    stack<pair<ll, ll>> s, t;

    for (int i = 0; i < n; i++) {
        cin >> x;
        // cout << x << ": ";
        max_el = -1;
        if (!s.empty() && x < s.top().second)
            max_el = s.top().second;

        while (!s.empty() && x < s.top().second) {
            top = s.top();
            s.pop();
        }

        // cout << max_el << ".";
        // x is max
        if (max_el == -1) {
            s.push({x, x});
        } else {
            // x is min,
            // s.top().second < x
            top = {min(x, top.first), max(max_el, x)};
            s.push(top);
        }

        // print(s, t);
    }
    cout << s.size();
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
