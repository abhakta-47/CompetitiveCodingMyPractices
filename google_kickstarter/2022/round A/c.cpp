#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n;
string s;
vector<map<string, bool>> m;

bool posPal(const string &x) {
    string tmp;
    bool flag1 = true, flag2 = true;

    if (x.length() < 5)
        flag1 = false;
    else {
        tmp = x.substr(x.length() - 5, 5);
        for (int i = 0; i < (tmp.length() / 2); i++)
            if (tmp[i] != tmp[tmp.length() - i - 1]) {
                flag1 = false;
                break;
            }
    }

    if (x.length() < 6)
        flag2 = false;
    else {
        tmp = x.substr(x.length() - 6, 6);
        for (int i = 0; i < (tmp.length() / 2); i++)
            if (tmp[i] != tmp[tmp.length() - i - 1]) {
                flag2 = false;
                break;
            }
        // cout << x << flag2 << " ";
    }
    bool ret = (flag1 || flag2);
    // cout << X << ":" << ret << " ";
    // cout << X << ":" << flag1 << flag2 << ret << " ";
    return ret;
}

bool isDone(int pos, string x) {
    if (x == "")
        return false;
    // cout << "?" << pos << x << ":" << (m[pos].find(x) != m[pos].end()) << "
    // ";
    return (m[pos].find(x) != m[pos].end());
}

string minStr(string x) {
    if (x.length() >= 5)
        return x.substr(x.length() - 5, 5);
    else
        return x;
}

void print() {
    cout << " ";
    for (int i = 0; i < n; i++)
        for (auto im : m[i])
            cout << i << "," << im.first << ":" << im.second << ",   ";
}

bool recur(int pos, string x) {
    x = minStr(x);
    // cout << pos;
    if (pos >= s.length()) {
        // if (~posPal(x))
        //     cout << x << ", ";
        return (~posPal(x));
    }
    if (isDone(pos, x) && x.length() >= 5) {
        cout << x << ":=" << m[pos][x];
        print();
        cout << "\n";
        return m[pos][x];
    }

    if (s[pos] != '?') {
        bool flag;
        if (posPal(x + s[pos]))
            flag = false;
        else
            flag = recur(pos + 1, x + s[pos]);
        m[pos][x] = flag;
        cout << x << "=" << m[pos][x];
        print();
        cout << "\n";
        return flag;
    }

    bool flag1 = false, flag2 = false;

    if (!posPal(x + '0'))
        flag1 = recur(pos + 1, x + '0');
    if (!posPal(x + '1'))
        flag2 = recur(pos + 1, x + '1');

    m[pos][x] = (flag1 || flag2);
    cout << x << "=" << m[pos][x];
    print();
    cout << "\n";
    return m[pos][x];
}

void sol() {
    cin >> n;
    cin >> s;
    m.resize(n, map<string, bool>());
    // for (int i = 0; i < n; i++)
    //     for (auto im : m[i])
    //         cout << im.first << ":" << im.second << ", ";
    cout << (recur(0, "") ? "POSSIBLE" : "IMPOSSIBLE");
    // for (int i = 0; i < n; i++)
    //     for (auto im : m[i])
    //         cout << im.first << ":" << im.second << ", ";
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
        cout << "\n";
    }
}
