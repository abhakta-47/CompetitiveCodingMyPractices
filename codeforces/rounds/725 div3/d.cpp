#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const ll N = 1'0;
vector<ll> primes;

void sieveOfEratosthenes()
{
    bool isPrime[N + 1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (isPrime[i] == true)
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= N; j += i)
                isPrime[j] = false;
        }
}

void sol()
{
    int a, b, k;
    cin >> a >> b >> k;
    // cout << a << b << k;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    sieveOfEratosthenes();
    for (auto i : primes)
        cout << i << " ";
    //     cin >> t;
    //     while (t--)
    //     {
    //         //cout<<"Case #"<<i+1<<": ";
    //         sol();
    //         cout << "\n";
    //     }
}
