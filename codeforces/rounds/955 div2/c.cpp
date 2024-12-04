#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

ll n, l, r;

bool bin_search(vector<ll> &a, ll lpos, ll rpos) {
    clog << lpos << "-" << rpos << " : ";
    while (lpos <= rpos) {
        ll mid = lpos + (rpos - lpos) / 2;
        clog << mid << "=" << a[mid] << ".";
        if (mid < 0 || mid >= n)
            return false;
        if (a[mid] < l)
            lpos = mid + 1;
        else if (a[mid] > r)
            rpos = mid - 1;

        if (a[mid] >= l && a[mid] <= r)
            return true;
    }
    return false;
}

void sol() {
    cin >> n >> l >> r;
    vector<ll> a(n), pre_sum(n);
    loop(i, 0, n) {
        cin >> a[i];
        if (i == 0)
            pre_sum[i] = a[i];
        else
            pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    ll win_count = 0, last_pos = 0;
    loop(i, 0, n) {
        clog << last_pos << "-" << i << " :: ";
        if (bin_search(pre_sum, last_pos, i)) {
            clog << "*";
            win_count++;
            last_pos = i + 1;
        }
    }

    cout << win_count;

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
        clog << "\nCase #" << i + 1 << ": \n";
        sol();
        // clog << "\n";
        cout << "\n";
    }
}
