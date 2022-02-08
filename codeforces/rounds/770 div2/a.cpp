#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        cout << 1;
        return;
    }
    // bool palindrome = false;
    for (int i = 0; i < (n / 2); i++)
        if (s[i] != s[n - i - 1]) {
            cout << 2;
            return;
        }

    cout << 1;
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
