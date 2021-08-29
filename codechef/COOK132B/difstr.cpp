#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

ll n;

bool isNext(string &before, string &after) {
    ll n = before.length();
    for (ll i = n - 1; i >= 0; i--)
        if (before[i] == '0' && before[i] == after[i])
            return false;
    return true;
}

void sol() {
    // ll n;
    cin >> n;
    string s;
    set<string> binStrs;
    loop(i, 0, n) {
        cin >> s;
        binStrs.insert(s);
    }
    if(binStrs.find())
    s = '0' * n;
    for (auto is : binStrs)
        if(isNext(s,is));
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
