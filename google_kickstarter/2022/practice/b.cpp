#include <iostream>

using namespace std;

bool isVowel(char c) {
    char vowels[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for (auto iv : vowels)
        if (iv == c)
            return true;
    return false;
}

string ruler(const string &s) {
    if (s[s.length() - 1] == 'y' || s[s.length() - 1] == 'Y')
        return "nobody";
    else if (isVowel(s[s.length() - 1]))
        return "Alice";
    else
        return "Bob";
}

void solve() {
    string s;
    cin >> s;
    cout << s << " is ruled by " << ruler(s) << ".";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
}