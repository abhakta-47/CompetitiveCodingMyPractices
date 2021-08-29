#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i <= n; i++)

string creator(string in, vector<char> &order, ll p) {
    // cout << in << " " << p << ", ";
    if (in == "")
        return "";
    string out = "";
    for (auto is : in) {
        if (is != order[p])
            out = out + is;
    }
    return (in + creator(out, order, p + 1));
}

void sol() {
    string s;
    cin >> s;
    map<char, ll> freq;
    vector<char> order;
    for (ll i = (s.length() - 1); i >= 0; i--) {
        if (freq.find(s[i]) == freq.end())
            order.pb(s[i]);
        freq[s[i]]++;
    }
    ll tFreq = freq.size(), orL = 0;
    for (ll i = 0; i < order.size(); i++) {
        // cout << order[i] << " " << freq[order[i]] << "\n";
        if (freq[order[i]] % (tFreq - i) == 0)
            orL += freq[order[i]] / (tFreq - i);
        else {
            // cout << order[i] << " ";
            cout << "-1";
            return;
        }
    }
    reverse(order.begin(), order.end());
    string posAns = s.substr(0, orL);
    if (s == creator(posAns, order, 0)) {
        cout << posAns << " ";
        for (auto iv : order)
            cout << iv;
    } else
        cout << "-1";
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
