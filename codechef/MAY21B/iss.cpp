#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

map<ll, vector<ll>> factors;
// ll LIMIT_K = 1E6 + 1;
// ll LIMIT_lt = 4 * 1E6 + 6;
// bool isPrime[(ll)(4 * 1E6 + 6)];
// vector<ll> primes;
// ll primeDivisor[(ll)(4 * 1E6 + 6)];

// void SieveOfEratosthenes()
// {
//     ll n = LIMIT_lt;
//     memset(isPrime, true, sizeof(isPrime));

//     isPrime[1] = false;

//     for (ll p = 2; p * p <= n; p++)
//     {
//         if (isPrime[p])
//         {
//             for (int i = p * 2; i <= n; i += p)
//             {
//                 isPrime[i] = false;
//                 primeDivisor[i] = p;
//             }
//         }
//     }

//     for (ll p = 2; p <= n; p++)
//         if (isPrime[p])
//             primes.pb(p);
// }

void getFactors(ll n)
{
    if (n == 0)
        return;

    if (factors.find(n) != factors.end())
        return;

    if (n == 1)
        factors[n].push_back(1);

    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
            if (i == n / i)
                factors[n].push_back(i);
            else
            {
                factors[n].push_back(i);
                factors[n].push_back(n / i);
            }
    sort(factors[n].begin(), factors[n].end());
}

void sol()
{
    ll k;
    cin >> k;
    ll lt = 4 * k + 1, ans = 0;
    clog << k << ": " << lt << "->\n";
    getFactors(lt);
    map<ll, ll> counter;
    vector<ll> &curFactors = factors[lt];
    for (auto factor = curFactors.rbegin();
         factor != curFactors.rend();
         factor++)
    {
        counter[*factor] += (2 * k - 1) / *factor;
        getFactors(*factor);
        clog << *factor << "->";
        for (auto itsFactor : factors[*factor])
        {
            if (itsFactor == *factor)
                break;
            clog << itsFactor << ",";
            counter[itsFactor] -= counter[*factor];
        }
    }
    counter[lt] = 1;
    for (auto counter_it : counter)
        clog << counter_it.first << "*"
             << counter_it.second << ", ";
    clog << "\n";

    // for (int i = curFactors.size() - 1; i >= 0; i--)
    //     for (int j = i + 1; j < curFactors.size() - 1; j++)
    //         if (curFactors[j] % curFactors[i] == 0)
    //             counter[curFactors[i]] -= counter[curFactors[j]];

    for (auto counter_it : counter)
    {
        // clog << counter_it.first << "*"
        //  << counter_it.second << ", ";
        ans += counter_it.first * counter_it.second;
    }
    cout << ans;
    clog << ans << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // SieveOfEratosthenes();
    // for (ll i = 1; i < LIMIT_K; i++)
    //     getFactors(4 * i + 1);
    int t;
    //t=1;
    cin >> t;
    int t2 = t;
    while (t--)
    {
        clog << "Case #" << t2 - t << ":\n";
        sol();
        clog << "\n";
        cout << "\n";
    }
}
