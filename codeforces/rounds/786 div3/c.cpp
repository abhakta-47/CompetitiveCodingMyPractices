#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string s, t;
    cin >> s >> t;

    bool a_present = false;
    for (auto is : t) {
        if (is == 'a') {
            a_present = true;
            break;
        }
    }

    if (!a_present)
        cout << (ll)pow(2, s.length());
    else {
        if (t.length() == 1)
            cout << 1;
        else
            cout << -1;
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
        cout << "\n";
    }
}
