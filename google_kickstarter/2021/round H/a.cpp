#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

int getDistance(char x, char y) {
    int d1 = (x > y ? x - y : y - x);
    int d2 = 26 - d1;
    return min(d1, d2);
}

void sol() {
    string s, f;
    cin >> s >> f;
    int ls = s.length(), lf = f.size();
    int distance[ls], ans = 0;
    for (int i = 0; i < ls; i++) {
        distance[i] = getDistance(s[i], f[0]);
        for (auto ic : f)
            distance[i] = min(distance[i], getDistance(s[i], ic));
        ans += distance[i];
    }
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
        // clog<<"\n";
        cout << "\n";
    }
}
