#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

bool isVowel(char c) {
    return ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'));
}

void sol() {
    string s;
    cin >> s;
    map<char, ll> v, c;
    for (auto is : s) {
        if (isVowel(is))
            v[is]++;
        else
            c[is]++;
    }

    ll tc = 0, mc = 0, tv = 0, mv = 0;
    for (auto im : v) {
        tv += im.second;
        mv = max(mv, im.second);
    }
    for (auto im : c) {
        tc += im.second;
        mc = max(mc, im.second);
    }

    cout << min(2 * (tv - mv) + tc, 2 * (tc - mc) + tv);
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
        // clog<<"\n";
        cout << "\n";
    }
}
