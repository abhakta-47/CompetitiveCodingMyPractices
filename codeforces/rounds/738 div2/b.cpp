#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    char ans[n];
    int first = -1;
    // cout << s << " ";
    for (int i = 0; i < n; i++)
        if (s[i] != '?') {
            first = i;
            break;
        }
    // cout << first << " : ";
    if (first != -1) {
        if (first % 2 == 0)
            ans[0] = s[first];
        else
            ans[0] = (s[first] == 'B' ? 'R' : 'B');
    } else
        ans[0] = 'B';
    for (int i = 1; i < n; i++) {
        if (s[i] == '?')
            ans[i] = (ans[i - 1] == 'B' ? 'R' : 'B');
        else
            ans[i] = s[i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i];

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
