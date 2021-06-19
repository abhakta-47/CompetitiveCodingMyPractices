#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sieveOfEratosthenes(int N, int s[])
{
    vector<bool> prime(N + 1, false);
    for (int i = 2; i <= N; i += 2)
        s[i] = 2;
    for (int i = 3; i <= N; i += 2)
    {
        if (prime[i] == false)
        {
            s[i] = i;
            for (int j = i; j * i <= N; j += 2)
            {
                if (prime[i * j] == false)
                {
                    prime[i * j] = true;
                    s[i * j] = i;
                }
            }
        }
    }
}

void generatePrimeFactors(int N)
{
    // s[i] is going to store smallest prime factor
    // of i.
    int s[N + 1];

    // Filling values in s[] using sieve
    sieveOfEratosthenes(N, s);

    printf("Factor Power\n");

    int curr = s[N]; // Current prime factor of N
    int cnt = 1;     // Power of current prime factor

    while (N > 1)
    {
        N /= s[N];
        if (curr == s[N])
        {
            cnt++;
            continue;
        }

        printf("%d\t%d\n", curr, cnt);
        curr = s[N];
        cnt = 1;
    }
}

void sol()
{
    int a, b, k;
    cin >> a >> b >> k;
    int gcd_ab = __gcd(a, b);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
