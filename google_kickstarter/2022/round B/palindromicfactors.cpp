#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

bool palindrome_number(ll x) {
    string s = to_string(x);
    loop(i, 0, s.length() / 2) {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

void sol() {
    ll n;
    cin >> n;
    ll ans = 0;
    loop(i, 1, pow(n, 0.5)) {
        if (n % i)
            continue;
        if (palindrome_number(i))
            ++ans;
        if (palindrome_number(n / i))
            ++ans;
    }
    if (pow(n, 0.5) * pow(n, 0.5) == n && palindrome_number(pow(n, 0.5)))
        ++ans;
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
        cout << "Case #" << i + 1 << ": ";
        sol();
        cout << "\n";
    }
}
