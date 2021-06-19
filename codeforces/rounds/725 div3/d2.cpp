/* When you get down to nothing.. */
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

ll primeFactors(ll n)
{
    ll count = 0;
    while (n % 2 == 0)
    {
        n = n / 2;
        count++;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
    }
    if (n > 2)
        count++;
    return count;
}

bool isPossible(ll a, ll b, ll k)
{
    if (!k)
    {
        if (a == b)
            return 1;
        return 0;
    }
    bool flag = 0;
    if (a > 1)
    {
        FOR(i, 1, floor(sqrt(a)) + 1)
        {
            if (a % i == 0)
            {
                if (i != 1)
                    flag |= isPossible(a / i, b, k - 1);
                if (!flag && i != a / i)
                    flag |= isPossible(i, b, k - 1);
            }
            if (flag)
                return flag;
        }
    }
    if (b > 1)
    {
        FOR(i, 1, floor(sqrt(b)) + 1)
        {
            if (b % i == 0)
            {
                if (i != 1)
                    flag |= isPossible(a, b / i, k - 1);
                if (!flag && i != b / i)
                    flag |= isPossible(a, i, k - 1);
            }
            if (flag)
                return flag;
        }
    }
    return flag;
}

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
        ll a, b, k;
        cin >> a >> b >> k;
        ll facA = primeFactors(a);
        ll facB = primeFactors(b);
        ll mx = facA + facB;
        if (k > mx)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (isPossible(a, b, k))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        // cout<<"Case #"<<t<<": ";
    }

    // cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
}
