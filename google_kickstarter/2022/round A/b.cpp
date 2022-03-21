#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string n;
    cin >> n;
    ll nn = n.length(), rem = 0;
    loop(i, 0, nn) {
        rem += (n[i] - '0');
        rem %= 9;
    }
    rem = (9 - rem) % 9;
    if (rem == 0) {
        cout << n[0] << "0" << n.substr(1, nn - 1);
        return;
    }
    ll i;
    for (i = 0; i < nn; i++) {
        if ((n[i] - '0') > rem) {
            cout << n.substr(0, i) << rem << n.substr(i, nn - i);
            return;
        }
    }
    // cout << rem << " " << i << " ";
    cout << n << rem;
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
