#include <bits/stdc++.h>

using namespace std;
vector<long> bitwiseEquations(vector<long> a, vector<long> b) {
    // long long x = 0, y = 0;
    int n = a.size();
    vector<long> ans(n);
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            ans[i] = 0;
            continue;
        }
        long x = 0, y = 0;
        long diff = a[i] - b[i];
        diff /= 2;
        // cout << diff << endl;
        for (int j = 0; j < 64; j++) {
            if (b[i] & (1 << j)) {
                if ((diff & (1 << j)) == 0) {
                    // x |= (1 << j);
                    y |= (1 << j);
                } else {
                    x = 0, y = 0;
                    break;
                }
            } else {
                if ((diff & (1 << j))) {
                    x |= (1 << j);
                    y |= (1 << j);
                }
            }
        }
        ans[i] = 2 * x + 3 * y;
    }
    return ans;
}
int main() {
    // vector<long> a = {29, 36, 57};
    // vector<long> b = {25, 18, 13};
    vector<long> a = {4, 3, 57};
    vector<long> b = {2, 4, 49};
    vector<long> ans = bitwiseEquations(a, b);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
