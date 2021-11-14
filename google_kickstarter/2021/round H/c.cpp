#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void stpr(const stack<char> &St) {
    stack<char> st = St;
    string newS;
    while (!st.empty()) {
        newS = st.top() + newS;
        st.pop();
    }
    cout << newS << ": ";
}

string util(const string &s) {
    string newS = "";
    int n = s.length();
    stack<char> st;
    st.push(s[0]);
    int i = 1;
    char cur, nxt;
    bool flg = false;
    for (int i = 1; i < n; i++) {
        nxt = s[i];
        // cout << nxt << "+ ";
        // stpr(st);
        flg = false;
        while (!st.empty()) {
            // stpr(st);
            // cout << "->";
            cur = st.top();
            st.pop();
            if (nxt - cur == 1)
                nxt = (cur == '8' ? '0' : char(nxt + 1));
            else if (cur == '9' && nxt == '0') {
                if (flg || i + 1 == n || (i + 2 < n && s[i + 1] != 1))
                    nxt = '1';
                else {
                    st.push(cur);
                    break;
                }
            } else {
                st.push(cur);
                break;
            }
            flg = true;
        }

        st.push(nxt);
    }
    while (!st.empty()) {
        newS = st.top() + newS;
        st.pop();
    }
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
