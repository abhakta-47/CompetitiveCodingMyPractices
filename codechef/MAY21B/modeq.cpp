#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

map<ll, vector<ll>> divisors;
bool isPrime[500001];
vector<ll> primes;
ll primeDivisor[500001];

void SieveOfEratosthenes()
{
    ll n = 5 * 1e5 + 1;
    memset(isPrime, true, sizeof(isPrime));

    isPrime[1] = false;

    for (ll p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * 2; i <= n; i += p)
            {
                isPrime[i] = false;
                primeDivisor[i] = p;
            }
        }
    }

    for (ll p = 2; p <= n; p++)
        if (isPrime[p])
            primes.pb(p);
}

void getDivisors(ll n)
{
    if (n == 0)
        return;

    if (divisors.find(n) != divisors.end())
        return;

    if (n == 1)
        divisors[n].push_back(1);
    if (isPrime[n])
    {
        divisors[n].push_back(1);
        divisors[n].push_back(n);
    }

    if (divisors.find(n) != divisors.end())
        return;

    vector<ll> &curDivisor = divisors[n];
    ll prime = primeDivisor[n];
    getDivisors(n / prime);
    // ll otherDivisor = n / prime;
    vector<ll> &otherDivisor = divisors[n / prime];
    auto otherDivIt1 = otherDivisor.begin();
    auto otherDivIt2 = otherDivisor.begin();
    // cout << prime << "," << n / prime << ": ";
    while (true)
    {
        if (otherDivIt1 == otherDivisor.end() && otherDivIt2 == otherDivisor.end())
            break;
        if (otherDivIt1 == otherDivisor.end())
        {
            curDivisor.pb(((*otherDivIt2) * prime));
            ++otherDivIt2;
            continue;
        }
        if (otherDivIt2 == otherDivisor.end())
        {
            curDivisor.pb(*otherDivIt1);
            ++otherDivIt1;
            continue;
        }
        if (*otherDivIt1 < ((*otherDivIt2) * prime))
        {
            curDivisor.pb(*otherDivIt1);
            ++otherDivIt1;
        }
        else if (*otherDivIt1 == ((*otherDivIt2) * prime))
        {
            curDivisor.pb(*otherDivIt1);
            ++otherDivIt1;
            ++otherDivIt2;
        }
        else // ((*otherDivIt2)*prime) < otherDivIt1
        {
            curDivisor.pb(((*otherDivIt2) * prime));
            ++otherDivIt2;
        }
    }
    // cout << ": ";
}

ll contSum(ll n, ll x) // x + ... + n
{
    // cout << "u:" << n << " l:" << x << " : ";
    --n;
    // if (x > 0)
    --x;
    ll sum = n * (n + 1) / 2 - (x - 1) * (x) / 2;
    // cout << "u:" << n << " l:" << x << " =" << sum;
    return sum;
}

void sol()
{
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << " ";
    // cout << "\n";
    ll ans = 0;
    for (int i = 0; i <= min(m, n - 1); i++)
    { // i=m%b
        // cout << m - i << "->";
        getDivisors(m - i);
        // cout << " ";
        // for (auto iv : divisors[m - i])
        //     cout << iv << ",";
        // cout << "\n";
    }

    for (int x = 0; x <= min(n - 1, m); x++) // x=m%b
    {
        // cout << m - x << "->";
        // cout << "m:" << m << " x:" << x << " m-x:" << m - x;
        if (x == m)
        {
            ans += contSum(n, m + 1);
            // cout << " *\n";
            continue;
        }
        vector<ll> &curDivisors = divisors[m - x];
        // cout << " ";
        // for (auto iv : curDivisors)
        // cout << iv << ",";
        // cout << " ";
        // x<
        ll lb = upper_bound(curDivisors.begin(), curDivisors.end(), x) - curDivisors.begin();
        // <=n
        ll ub = upper_bound(curDivisors.begin(), curDivisors.end(), n) - curDivisors.begin();
        if (lb < ub)
            ans += contSum(ub, lb + 1);
        // cout<<" ub:"<<ub<<" lb:"<<lb+1;
        // cout << "\n";
    }

    cout << ans;
    // cout << " ::=\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    SieveOfEratosthenes();
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        ////cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
