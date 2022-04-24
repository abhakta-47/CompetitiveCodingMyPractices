#include <bits/stdc++.h>

using namespace std;

#define ll int
#define pb push_back
#define loop(i, x, n) for (ll i = x; i < n; i++)

ll getVal(char c) {
    if ('0' <= c && c <= '9')
        return (c - '0');
    if ('A' <= c && c <= 'Z')
        return (c - 'A' + 10);
    if ('a' <= c && c <= 'z')
        return (c - 'a' + 36);

    return 0;
}

ll getBase(char c) {
    ll val = getVal(c);
    return (val == 0 ? 2 : val + 1);
}

ll getDec(string elm) {

    if (elm.length() == 1)
        return getVal(elm[0]);

    ll val1 = getVal(elm[0]);
    ll base = getBase(elm[0]);
    ll val2 = getVal(elm[1]);
    ll ans = (val2 * base + val1);
    // clog << elm << ":" << ans << ", ";
    return ans;
}

void parseInput(const string &input, vector<string> &ans) {
    // vector<string> ans;
    string word = "";
    ll n = input.length();
    for (ll i = 0; i < (ll)n; i++) {
        if (input[i] == ' ') {
            if (word != "")
                ans.push_back(word);
            word = "";
        } else
            word = word + input[i];
    }
    if (word != "")
        ans.push_back(word);
    // return ans;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    string input;
    getline(cin, input);
    vector<string> elms;
    parseInput(input, elms);

    vector<ll> values;
    for (auto elm : elms)
        values.push_back(getDec(elm));

    ll n = values.size();
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ans = max(ans, (ll)__gcd(values[i], values[j]));
        }
    }
    cout << ans;
    return 0;
}
