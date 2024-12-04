#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll start = 3;
void print(ll n) {
    loop(i, 0, n) cout << start + i << " " << start + i << " ";
    start += n;
}

void sol() {
    start = 3;
    ll n;
    cin >> n;
    if (n < 27 && n % 2) {
        cout << "-1";
        return;
    }
    if (n % 2 == 0) {
        print(n / 2);
        return;
    }
    cout << "1 ";
    print(4); // 8
    cout << "1 2 ";
    print(7); // 14
    cout << "1 2 ";
    print((n - 27) / 2);

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
