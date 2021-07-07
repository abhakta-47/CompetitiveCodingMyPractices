#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        // test cases starts here
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll cnt1 = 0, pos = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                cnt1++;
                if (pos == -1)
                    pos = i;
            }
        }
        vector<ll> fac;
        for (ll i = 1; i < floor(sqrt(n)) + 1; i++)
        {
            if (n % i == 0)
            {
                fac.push_back(i);
                if (n / i != i)
                    fac.push_back(n / i);
            }
        }
        ll ans = LLONG_MAX;
        for (auto &x : fac)
        {
            ll st = pos, res = 0, prev = 0;
            if (st == -1)
                st = 0;
            do
            {
                if (s[st] == '1')
                    prev++;
                else
                    res++;
                st = (st + x) % n;
            } while ((cnt1 && st != pos) || (!cnt1 && st));
            // } while ((pos != -1 && st != pos) || (pos == -1 && st));
            res += cnt1 - prev;
            ans = min(ans, res);
        }
        cout << ans << endl;
    }
}
