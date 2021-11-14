#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

string util(const string &s, const char c1) {
    int n, i;
    string newS = "";
    char c2;
    c2 = (c1 == '9' ? '0' : char(c1 + 1));
    n = s.length();
    // cout << "\n" << c1 << c2 << ": ";
    for (i = 0; i < n; i++) {
        if (s[i] == c1 && s[i + 1] == c2) {

            newS += (s[i] == '8' ? '0' : char(c2 + 1));
            ++i;

        } else {
            newS += s[i];
        }
        // cout << newS << ",";
    }

    return newS;
}
string util(const string &s) {
    string newS = "";
    newS = util(s, '0');
    newS = util(newS, '1');
    newS = util(newS, '2');
    newS = util(newS, '3');
    newS = util(newS, '4');
    newS = util(newS, '5');
    newS = util(newS, '6');
    newS = util(newS, '7');
    newS = util(newS, '8');
    newS = util(newS, '9');
    return (s == newS ? s : util(newS));
}

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    cout << util(s);
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
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
