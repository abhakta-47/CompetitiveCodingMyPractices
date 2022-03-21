#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, m;
    cin >> n >> m;
    ll a[n], bad[m][2];
    set<pair<ll, ll>> bads;
    unordered_map<ll, ll> freq;
    loop(i, 0, n) {
        cin >> a[i];
        freq[a[i]]++;
    }
    loop(i, 0, m) {
        cin >> bad[i][0];
        cin >> bad[i][1];
        if (bad[i][0] < bad[i][1])
            bads.insert({bad[i][0], bad[i][1]});
        else
            bads.insert({bad[i][1], bad[i][0]});
    }
    ll ans = 0;
    for (auto im1 = freq.begin(); im1 != freq.end(); im1++) {
        for (auto im2 = im1; im2 != freq.end(); im2++) {
            if (im1->first == im2->first)
                continue;
            if ((bads.find({im1->first, im2->first}) != bads.end()) ||
                (bads.find({im2->first, im1->first}) != bads.end()))
                continue;
            // cout << im1->first << " " << im2->first << ", ";
            ans = max(ans,
                      (im1->first + im2->first) * (im1->second + im2->second));
        }
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
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
