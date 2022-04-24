#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

string string_repeat(string s, int n) {
    string ans = "";
    loop(i, 0, n) ans += s;
    return ans;
}

void sol() {
    ll r, c;
    cin >> r >> c;
    string border = string_repeat("+-", c) + "+";
    string line = string_repeat("|.", c) + "|";
    string ans[2 * r + 1];
    loop(i, 0, 2 * r) { ans[i] = (i % 2 ? line : border); }
    ans[2 * r] = border;
    ans[0][0] = '.';
    ans[0][1] = '.';
    ans[1][0] = '.';
    loop(i, 0, 2 * r + 1) cout << ans[i] << "\n";
    // cout << border << "\n" << line;

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
        cout << "Case #" << i + 1 << ":\n";
        sol();
        // cout << "\n";
    }
}
