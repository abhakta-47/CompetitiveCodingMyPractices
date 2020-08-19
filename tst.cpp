#include <bits/stdc++.h>

using namespace std;

#define ll long int

#define repp(i, b) for (ll i = 0; i < (b); i++)

int main()
{

    ll n, m;

    cin >> n >> m;

    ll arr[n];

    repp(i, n)
    {

        cin >> arr[i];
    }

    repp(i, m)
    {

        ll x;

        cin >> x;

        if (x == 1)
        {

            ll sw;

            cin >> sw;

            arr[sw - 1] ^= 1;
        }

        else
        {

            ll l, r;

            cin >> l >> r;

            if (arr[r - 1] & 1)
            {

                cout << "ODD"
                     << "\n"
                     << endl;
            }

            else
            {

                cout << "EVEN"
                     << "\n"
                     << endl;
            }
        }
    }

    return 0;
}