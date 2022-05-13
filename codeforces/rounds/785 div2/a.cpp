#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string s;
    cin >> s;
    ll n = s.length(), score = 0;
    loop(i, 0, n) score += (s[i] - 'a' + 1);

    ll alice = 0, bob = 0;
    if (n % 2)
        bob = (min(s[0], s[n - 1]) - 'a' + 1);
    else
        bob = 0;

    alice = score - bob;
    if (alice > bob)
        cout << "Alice " << alice - bob;
    else
        cout << "Bob " << bob - alice;

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
