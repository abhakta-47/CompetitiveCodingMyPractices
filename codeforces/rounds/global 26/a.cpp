#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<int> a(n);
    loop(i, 0, n) { cin >> a[i]; }
    int b_pos = -1;
    loop(i, 1, n) {
        if (a[i] != a[i - 1]) {
            b_pos = i;
            break;
        }
    }

    if (b_pos == -1) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    if (b_pos == 2)
        cout << "RBR";
    else
        cout << "RRB";
    loop(i, 0, n - 3) { cout << "R"; }

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
