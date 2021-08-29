#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void toBits(ll x, bool *bits) {
    ll pos = 0;
    while (x) {
        bits[pos] = x % 2;
        x /= 2;
        pos++;
    }
}

void sol() {
    ll n;
    cin >> n;
    ll up[n], down[n];
    loop(i, 0, n) cin >> up[i];
    loop(i, 0, n) cin >> down[i];
    bool bits[n][2][30];
    memset(bits, 0, sizeof(bits));
    loop(i, 0, n) {
        toBits(up[i], bits[i][0]);
        toBits(down[i], bits[i][1]);
    }
    // for (ll i = 0; i < n; i++) {
    //     cout << up[i] << "->";
    //     for (auto it : bits[i][0])
    //         cout << it;
    //     cout << "\n";
    //     cout << down[i] << "->";
    //     for (auto it : bits[i][1])
    //         cout << it;
    //     cout << "\n";
    // }
    bool isUsed[n] = {0};
    ll flipCnt = 0;
    for (ll pos = 29; pos >= 0; pos--) {
        // cout << " " << pos << ":";
        bool canHigh = true;
        loop(i, 0, n) {
            if ((bits[i][0][pos] == 0 && bits[i][1][pos] == 0) ||
                ((isUsed[i]) && (bits[i][0][pos] == 0)) ||
                ((!isUsed[i]) &&
                 (bits[i][0][pos] == 0 && bits[i][1][pos] == 0))) {
                canHigh = false;
                // cout << "X";
                break;
            }
        }
        if (canHigh)
            loop(i, 0, n) {
                if (isUsed[i])
                    continue;
                if (!isUsed[i] && bits[i][0][pos] == 1 &&
                    bits[i][1][pos] == 0) {
                    isUsed[i] = true;
                    continue;
                }
                if (!isUsed[i])
                    if ((bits[i][0][pos] == 0 && bits[i][1][pos] == 1)) {
                        // cout << i << ", ";
                        flipCnt++;
                        isUsed[i] = true;
                        swap(up[i], down[i]);
                        swap(bits[i][0], bits[i][1]);
                    }
            }
    }
    ll ans = up[0];
    loop(i, 1, n) ans = ans & up[i];
    cout << ans << " " << flipCnt;
    // cout << "\n";

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
