#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    int x = 0, t, lgn = floor(log2(n)), pown = pow(2, lgn);
    for (int i = 0; i < lgn; i++) {
        t = 1;
        for (int i = 1; i <= lgn; i++) {
            cout << x << " ";
            t *= 2;
            if (i != lgn)
                x = x ^ t;
        }
        cout << ", ";
    }

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
