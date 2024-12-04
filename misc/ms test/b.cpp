#include <bits/stdc++.h>
using namespace std;

vector<long> bitwiseEquations(vector<long> a, vector<long> b) {
    int n = a.size();
    vector<long> ans(n);

    for (int i = 0; i < n; i++) {
        // If a[i] < b[i], it's impossible to have x and y satisfying the
        // equation, so store 0
        if (a[i] < b[i]) {
            ans[i] = 0;
            continue;
        }

        long x = 0, y = 0;
        long diff = a[i] - b[i];

        // diff must be divisible by 2, otherwise no solution exists
        if (diff % 2 != 0) {
            ans[i] = 0;
            continue;
        }

        diff /= 2;

        bool valid = true;
        for (int j = 0; j < 64; j++) {
            if (b[i] & (1LL << j)) {
                // If the j-th bit of b[i] is set
                if ((diff & (1LL << j)) == 0) {
                    y |= (1LL << j);
                } else {
                    // Invalid configuration, reset x and y and break
                    x = 0;
                    y = 0;
                    valid = false;
                    break;
                }
            } else {
                // If the j-th bit of b[i] is not set
                if (diff & (1LL << j)) {
                    x |= (1LL << j);
                    y |= (1LL << j);
                }
            }
        }
        cout << x << " " << y << endl;
        if (valid) {
            ans[i] = 2 * x + 3 * y;
        } else {
            ans[i] = 0;
        }
    }

    return ans;
}

int main() {
    vector<long> a = {4, 3, 57};
    vector<long> b = {2, 4, 49};
    vector<long> result = bitwiseEquations(a, b);

    for (long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}