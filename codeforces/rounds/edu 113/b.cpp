#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n;
string s;
vector<vector<char>> ans;

void setDraw(int x, int y) {

    if (x == y) {
        ans[x][x] = 'X';
        return;
    }
    ans[x][y] = '=';
    ans[y][x] = '=';
}

void setWinner(int x, int y) {

    if (x == y) {
        ans[x][x] = 'X';
        return;
    }
    ans[x][y] = '+';
    ans[y][x] = '-';
}

bool isValid() {
    bool wins = false;
    for (int i = 0; i < n; i++) {
        wins = false;
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == '-' && s[i] == '1') {
                cout << 1;
                return false;
            }
            if (ans[i][j] == '+')
                wins = true;
        }
        if (s[i] == '2' && !wins) {
            cout << "2" << i;
            return false;
        }
    }
    return true;
}

void sol() {
    cin >> n;
    cin >> s;
    ans.clear();
    ans.resize(n, vector<char>(n, '='));
    set<int> p1;
    set<int> p2;

    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            p1.insert(i);
        else
            p2.insert(i);

    for (auto is : p1)
        for (auto js : p1)
            setDraw(is, js);

    int tmp;
    if (p2.size() == 1) {
        cout << "NO\n";
        return;
    }
    for (auto is = p2.begin(); is != p2.end(); is++) {
        tmp = *is;
        if (++is == p2.end())
            break;
        setWinner(tmp, *is);
        --is;
    }
    setWinner(*(--p2.end()), *(p2.begin()));

    if (!isValid()) {
        cout << "NO\n";
        // return;
    }
    cout << "YES\n";
    for (auto ir : ans) {
        for (auto ie : ir)
            cout << ie;
        cout << "\n";
    }

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
        // cout << "\n";
    }
}
