#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string s;
    cin >> s;
    ll n = s.length(), ans = s.length() - 1, i;
    for (i = 0; i < (n / 2); i++) {
        if (s[i] == s[n - i - 1])
            --ans;
        else
            break;
    }
    if (i == (n / 2))
        cout << 0;
    else
        cout << ans;

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
