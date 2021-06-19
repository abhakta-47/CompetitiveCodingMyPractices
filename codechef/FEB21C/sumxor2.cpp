#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
ll mod = 998244353;

ll n;
vector<ll> a;
ll bits[31];

ll getNcR(ll nofncr, ll k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > nofncr - k)
        k = nofncr - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ll i = 0; i < k; ++i)
    {
        res *= (nofncr - i);
        res /= (i + 1);
    }

    return res;
}

void bit_counter()
{
    ll k = 0;

    for (ll i = 0; i < 32; i++)
    {
        //  Count of zeros and ones
        ll oc = 0;

        for (ll j = 0; j < a.size(); j++)
        {
            if (a[j] % 2 != 0)
                oc++;
            a[j] /= 2;
        }
        bits[i] = (oc);
    }
}

ll func()
{

    ll n, i;
    cin >> n;
    a.resize(n);
    for (i = 0; i < n; i++)
        cin >> a[i];

    bit_counter();

    for (i = 0; i < 32; i++)
        cout << bits[i] << " ";
    cout << "\n";

    ll q, m, n_1, n_0, t, t1 = 0, ans[n] = {0};
    cin >> q;

    for (m = 1; m <= n; m++)
    {
        ll ans_m = 0;
        for (ll bitpos = 0; bitpos < 32; bitpos++)
        {
            n_1 = bits[bitpos];
            n_0 = n - n_1;
            t = 0;
            t1 = 1;
            cout << bitpos << " - " << n_1 << " " << n_0 << " " << max(t1, m - n_0) << " => " << min(n_1, m) << "-> ";
            for (i = max(t1, m - n_0); i <= min(n_1, m); i += 2)
            {
                if (i % 2 == 0)
                    ++i;

                cout << i << " " << getNcR(n_1, i) << " " << getNcR(n_0, m - i) << "\n";
                t += ((getNcR(n_1, i) % mod) * (getNcR(n_0, m - i) % mod)) % mod;
                t %= mod;
            }
            cout << "t " << t << " " << (t % mod * (1 << bitpos) % mod) % mod << " \n";
            ans_m += (t % mod * (1 << bitpos) % mod) % mod;
            ans_m %= mod;
        }
        cout << "  ***** ans_m ******   ";
        cout << ans_m << "\n\n";
        ans[m] = (m == 0 ? ans_m % mod : (ans[m - 1] % mod + ans_m % mod) % mod);
    }

    cout << "\n************ Queries *************\n";
    while (q--)
    {
        cin >> m;
        cout << ans[m] << "\n";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    t = 1;
    //cin>>t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
