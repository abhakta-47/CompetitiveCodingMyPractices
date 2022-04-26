#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)
string laststr = "00000000";
ll lastx = -1;

string genbytestr(int x) {
    if (x == lastx) {
        x = (x + 1) % 8;
    }
    string ans = string(x, '1') + string(8 - x, '0');
    // if (x == lastx) {
    //     ans = (laststr[7] + laststr);
    //     // cout << ans.length() << ":";
    //     ans = ans.substr(0, 8);
    // }
    laststr = ans;
    lastx = x;
    return ans;
}

void sol() {
    ll prompt = 8;
    while (true) {
        cout << genbytestr(8 - prompt) << "\n";
        cin >> prompt;
        if (prompt == 0)
            break;
        if (prompt == -1)
            exit(0);
        if (prompt > 4)
            prompt = 0;
    }

    return;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // cout << "Case #" << i + 1 << ": ";
        sol();
        // cout << "\n";
    }
}
