#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

struct freq
{
    ll odd, even;
    freq()
    {
        odd = 0;
        even = 0;
    }
    void change(ll x)
    {
        (x % 2) ? odd++ : even++;
    }
    bool operator==(freq &x)
    {
        return (odd == x.odd && even == x.even);
    }
    bool operator!=(freq &x)
    {
        return (!(odd == x.odd && even == x.even));
    }
};

void sol()
{
    ll n;
    cin >> n;
    ll x;
    ll a[n];
    map<ll, freq> oldPos, newPos;
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
        oldPos[a[i]].change(i);
    }
    sort(a, a + n);
    for (auto i = 0; i < n; i++)
        newPos[a[i]].change(i);

    // for (auto im : oldPos)
    //     cout << im.first << " = "
    //          << im.second.odd << " "
    //          << im.second.even << "\n";
    // for (auto im : newPos)
    //     cout << im.first << " = "
    //          << im.second.odd << " "
    //          << im.second.even << "\n";
    for (auto im : oldPos)
        if (im.second != newPos[im.first])
        {
            cout << "NO";
            return;
        }
    cout << "YES";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
