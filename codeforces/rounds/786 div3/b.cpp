#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll todigit(char c) { return (c - 'a'); }

void sol() {
    string s;
    cin >> s;
    ll x = todigit(s[0]) * 25 + todigit(s[1]);
    if (s[0] > s[1])
        x++;
    // cout << s << " ";
    cout << x;
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
