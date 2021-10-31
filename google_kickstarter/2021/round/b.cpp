#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<pair<int, int>> points(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points[i] = {x, y};
    }

    cin >> x >> y;
    pair<ll, ll> blue = {x, y};
    for (int i1 = 0; i1 < n; i1++)
        for (int i2 = 0; i2 < n; i2++)
            if (i1 != i2)
                for (int i3 = 0; i3 < n; i3++)
                    if (i1 != i3 && i2 != 3)
                        for (int i4 = 0; i4 < n; i4++)
                            if (i1 != i2 && i2 != i4 && i3 != i4)
                                square(points[i4], points[i1], points[i2],
                                       points[i3], blue);

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
