*When you get down to nothing..* /
#include <bits/stdc++.h>
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);
#define ll long long
#define ull unsigned ll
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
    using namespace std;

const int MAX = 1e6 + 5;
const int mod = 1e9 + 7;
const ld pi = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    clock_t clk = clock();
    sync int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        // test cases starts here
        ll n;
        cin >> n;
        vll a(2 * n);
        FOR(i, 0, n)
        cin >> a[i];
        sort(all(a));
        for (int i = 1; i < 2 * n; i += 2)
        {
            if (i + 2 < 2 * n)
            {
                swap(a[i], a[i + 2]);
            }
        }
        for (auto &x : a)
            cout << x << " ";
        cout << endl;

        // cout<<"Case #"<<t<<": ";
    }

    // cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
}