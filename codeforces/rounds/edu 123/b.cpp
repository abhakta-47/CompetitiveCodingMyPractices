#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)
void print(vector<vector<ll>> &list) {
    for (auto iv : list) {
        for (int i = iv.size() - 1; i >= 0; i--)
            cout << iv[i] << " ";
        cout << "\n";
    }
}
void sol() {
    ll n;
    cin >> n;
    ll a[n], maxa = 0;
    loop(i, 0, n) {
        cin >> a[i];
        maxa = max(a[i], maxa);
    }
    vector<vector<ll>> dp[maxa + 1];
    dp[3] = {{1, 2, 3}, {1, 3, 2}, {2, 3, 1}};
    loop(i, 4, maxa + 1) {
        dp[i] = dp[i - 1];
        dp[i].push_back(dp[i - 1][i - 2]);
        loop(j, 0, i) { dp[i][j].push_back(i); }
        swap(dp[i][i - 1][i - 2], dp[i][i - 1][i - 1]);
    }
    loop(i, 0, n) {
        // cout << a[i] << " :";
        print(dp[a[i]]);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
