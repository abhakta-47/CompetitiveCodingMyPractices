#include <bits/stdc++.h>
#define ll long long
#define vec vector<ll>
#define pa pair<ll, ll>
#define ve vector<string>
#define pb push_back
#define mp make_pair
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define MOD 10
using namespace std;
int main()
{
    fio
        ll t;
    cin >> t;
    while (t--)
    {
        ll k, a, b;
        cin >> k >> a >> b;
        ll sum = a + b;
        ll temp = sum % MOD;
        vector<ll> v;
        for (ll i = 0; i < 4; i++)
        {
            temp *= 2;
            temp = temp % MOD;
            v.push_back(temp);
        }
        //for(auto &x:v)  cout<<x<<"\n";
        if (sum % MOD == 0)
        {
            cout << "NO\n";
        }
        else if (k == 2)
        {
            cout << ((sum % 3 == 0) ? "YES\n" : "NO\n");
        }
        else if (k == 3)
        {
            sum += (a + b);
            cout << ((sum % 3 == 0) ? "YES\n" : "NO\n");
        }
        else
        {
            sum += (a + b);
            k -= 3;
            temp = floor(k / 4.0);
            //<<temp<<"\n";
            if (temp % 3 == 2)
                sum += 1;
            else if (temp % 3 == 1)
                sum += 2;
            temp = k % 4;
            //cout<<temp<<"\n";
            for (ll i = 0; i < temp; i++)
            {
                sum += v[i];
            }
            //cout<<sum<<"\n";
            cout << ((sum % 3 == 0) ? "YES\n" : "NO\n");
        }
    }
}