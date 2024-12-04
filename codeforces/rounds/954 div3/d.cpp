#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

int get_number(string &s, ll pos) {
    ll ans = (s[pos] - '0') * 10 + (s[pos + 1] - '0');
    return ans;
}

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if (n <= 2) {
        cout << get_number(s, 0);
        return;
    }

    if (n > 3) {
        loop(i, 0, n - 1) {
            if (s[i] == '0') {
                cout << 0;
                return;
            }
        }
    }
    if (n == 3 && (s[0] == '0' || s[2] == '0')) {
        cout << 0;
        return;
    }

    ll bestidx = 0;
    loop(i, 0, n - 1) {
        if (get_number(s, bestidx) > get_number(s, i)) {
            bestidx = i;
        }
    }

    vector<ll> numbers;
    loop(i, 0, n) {
        if (i == bestidx) {
            if (get_number(s, i) != 1)
                numbers.pb(get_number(s, i));
            i++;
        } else {
            if (s[i] != '1')
                numbers.pb(s[i] - '0');
        }
    }
    if (numbers.size() == 0) {
        cout << 1;
        return;
    }
    ll ans = numbers[0];
    loop(i, 1, numbers.size()) {
        if (numbers[i] == 1 || numbers[i - 1] == 1) {
            // ans += numbers[i] * numbers[i - 1];
            continue;
        } else {
            ans += numbers[i];
        }
    }
    cout << s << "." << get_number(s, bestidx) << "= ";
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
