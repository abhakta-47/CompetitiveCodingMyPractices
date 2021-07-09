#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n, x;
    cin >> n;
    set<pair<ll, ll>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert({x, (i + 1)});
    }

    int x1, l = 2 * n, ans = 0;
    for (auto is = s.begin(); is != s.end(); is++)
    {
        x1 = is->second;
        // cout << is->first << " -> ";
        for (auto is1 = is; (is->first * (is1->first) <= l) && is1 != s.end(); is1++)
        {
            if (is->first == is1->first)
                continue;
            // cout << is1->first << ", ";
            if (((is->first) * (is1->first)) == (x1 + is1->second))
                ++ans;
        }
        // cout << "\n";
    }

    cout << ans;

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
