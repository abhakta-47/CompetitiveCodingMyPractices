#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;

    multiset<ll> s;

    ll x, lel = 0;
    auto cur = s.begin();

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
        if (s.size() == 1) {
            lel = 1;
            cur = s.begin();
        } else {
            if (x >= *cur) {
                // cout << "+";
                ++lel;
            }
            do {
                if (cur == s.begin())
                    break;
                // cout << "*";
                --cur;
                ++lel;
            } while (*cur >= lel);
            while (cur != s.end() && *cur < lel) {
                // cout << ".";
                ++cur;
                --lel;
            }
        }
        // cout << "x:" << x << ", ";
        // for (auto tmp = cur; tmp != s.end(); tmp++)
        //     cout << *tmp << ",";

        // cout << " lel:" << lel << ":";
        // cout << min(lel, *cur) << "    ";
        cout << min(lel, *cur) << " ";
    }

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
        cout << "Case #" << i + 1 << ": ";
        sol();
        cout << "\n";
    }
}
