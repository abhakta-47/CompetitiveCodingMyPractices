#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    int left, right, aMax = -1, bMax = -1;
    for (int i = 0; i < a.size(); i++) {
        if (i != 0)
            a[i] += a[i - 1];
        if (a[i] > maxSum)
            break;
        aMax = i;
    }
    for (int i = 0; i < b.size(); i++) {
        if (i != 0)
            b[i] += b[i - 1];
        if (b[i] > maxSum)
            break;
        bMax = i;
    }
    int curSum, ans = (max(aMax, bMax) + 1);
    left = 0;
    right = bMax;
    while (left <= aMax && 0 <= right) {
        curSum = a[left] + b[right];
        if (curSum > maxSum)
            --right;
        else {
            ans = max(left + right + 2, ans);
            ++left;
        }
    }
    left = 0;
    right = aMax;
    while (left <= bMax && 0 <= right) {
        curSum = b[left] + a[right];
        if (curSum > maxSum)
            --right;
        else {
            ans = max(left + right + 2, ans);
            ++left;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, maxSum;
    cin >> n >> m >> maxSum;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(maxSum, a, b);
    cout << result;
    return 0;
}