//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/avoid-traps-0b92455e/
#include <bits/stdc++.h>

using namespace std;

#define dout cout
#define ll long long
#define pb push_back

bool prime[100001];

void SieveOfEratosthenes(int n)
{
    // bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
void sol()
{
    ll r1, r2, n;
    cin >> r1 >> r2 >> n;
    string s;
    cin >> s;
    s = '0' + s;
    if (s[n] == '*' || s[1] == '*')
    {
        cout << "No way!";
        return;
    }
    ll dp[n + 1];
    for (ll i = 1; i <= n; i++)
        dp[i] = 1e9;
    ll primeCount = 0;
    ll isPrimeJump[n + 1];
    memset(isPrimeJump, -1, sizeof(isPrimeJump));
    dp[1] = 0;
    for (ll i = 1; i <= n; i++)
    {
        // cout << i << "->";
        if (prime[i])
        {
            ++primeCount;
        }
        if (primeCount * r2 >= i * r1 && i + primeCount <= n)
        {
            isPrimeJump[i + primeCount] = i;
            // cout<<" p"<<i<<"->"<<i+primeCount<<" ";
        }
        if (s[i] == '#')
        {
            if (i > 1 && s[i - 1] == '#')
                dp[i] = min(dp[i], 1 + dp[i - 1]);
            if (i > 2 && s[i - 2] == '#')
                dp[i] = min(dp[i], 1 + dp[i - 2]);
            if (!isPrimeJump[i] != -1)
            {
                // cout << ".";
                // for (auto primeJump : isPrimeJump[i])
                ll primeJump = isPrimeJump[i];
                if (s[primeJump] == '#')
                    dp[i] = min(dp[i], 1 + dp[primeJump]);
            }
        }
        // cout << dp[i] << " ";
    }
    if (dp[n] == 1e9)
    {
        cout << "No way!";
        return;
    }
    cout << dp[n];

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    SieveOfEratosthenes(100001);

    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
