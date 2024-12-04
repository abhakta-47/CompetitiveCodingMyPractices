#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll sum = 0, x, maxsum = 0;
    for (int j = 2; j <= n; j++) {
        sum = 0;
        for (int i = 1; i * j <= n; i++) {
            sum += i * j;
        }
        if (sum > maxsum) {
            x = j;
            maxsum = sum;
        }
    }
    cout << x;
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
