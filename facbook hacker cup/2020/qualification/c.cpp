#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

class Tree {
  public:
    ll height, pos;
    Tree(ll h = 0, ll p = 0) : height(h), pos(p) {}
    void setValues(ll h, ll p) {
        height = h;
        pos = p;
    }
};

void sol() {
    ll n;
    cin >> n;
    Tree trees[n];
    ll p, h;
    for (ll i = 0; i < n; i++) {
        cin >> p >> h;
        trees[i].setValues(h, p);
    }
    ll dp[2][p + 1];
    for (int i = 0; i < n; i++)
        if (trees[i].height == trees[i].pos - trees[i - 1].pos)
            dp[0][i] = dp[0][i - 1] + trees[i].height;
    if (trees[i].height == trees[i + 1].pos - trees[i].pos)
        dp[1][i] = dp[1][i - 1] + trees[i].height;
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
