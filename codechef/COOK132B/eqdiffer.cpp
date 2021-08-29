#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> freq;
    ll maxFreq = 0;
    loop(i, 0, n) {
        cin >> a[i];
        freq[a[i]]++;
        maxFreq = max(maxFreq, freq[a[i]]);
    }
    if (n <= 2)
        cout << 0;
    else if (n == 3)
        cout << min((ll)1, n - maxFreq);
    else
        cout << n - maxFreq;

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
