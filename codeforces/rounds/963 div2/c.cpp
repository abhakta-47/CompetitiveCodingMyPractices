#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, k;

ostream &operator<<(ostream &os, const pair<ll, ll> &a) {
    os << "{" << a.first << "," << a.second << "}";
    return os;
}

pair<ll, ll> get_common(pair<ll, ll> a, pair<ll, ll> b) {
    // clog << "common " << a << " " << b << " ";

    if (a.first == -1 || b.first == -1) {
        return {-1, -1};
    }

    if (a.first > b.first)
        swap(a, b);

    pair<ll, ll> ans1, ans2;
    int start_diff = b.first - a.first;

    int extra = 2 * k * (start_diff / (2 * k));

    ans1 = {a.first + extra, a.second + extra};
    ans2 = {ans1.first + 2 * k, ans1.second + 2 * k};

    // clog << ans1 << ":" << ans2 << ":: ";

    pair<ll, ll> ans;
    if (ans1.first <= b.first && b.first < ans1.second)
        ans = {b.first, ans1.second};
    else if (ans1.first < b.second && b.second <= ans1.second)
        ans = {ans1.first, b.second};
    else if (b.first <= ans1.first && ans1.second <= b.second)
        ans = ans1;
    else if (ans2.first <= b.first && b.first < ans2.second)
        ans = {b.first, ans2.second};
    else if (ans2.first < b.second && b.second <= ans2.second)
        ans = {ans2.first, b.second};
    else if (b.first <= ans2.first && ans2.second <= b.second)
        ans = ans2;
    else
        ans = {-1, -1};

    // clog << ans << "\n";
    return ans;
}

pair<ll, ll> get_common(pair<ll, ll> a, ll b) {
    return get_common(a, {b, b + k});
}

pair<ll, ll> get_common(ll a, ll b) {

    if (a > b)
        swap(a, b);

    return get_common({a, a + k}, {b, b + k});
}

void sol() {
    cin >> n >> k;
    // clog << n << " " << k << "::\n";
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0];
        return;
    }
    sort(a.begin(), a.end());

    pair<ll, ll> cur_common = get_common(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        cur_common = get_common(cur_common, a[i]);
    }

    cout << cur_common.first;
    // clog << cur_common.first << "\n";
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
