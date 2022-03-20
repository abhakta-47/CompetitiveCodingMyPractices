#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll t = n;
    ll fo = 0, fe = 0;
    while (n) {
        if ((n % 10) % 2)
            fo++;
        else
            fe++;
        n = n / 10;
    }
    if ((t % 2 == 1 && fo >= 2) || (t % 2 == 0 && fe >= 2))
        cout << "yes";
    else
        cout << "no";

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
