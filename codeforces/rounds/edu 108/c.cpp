#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n;
    cin >> n;
    ll u[n], s[n], i;
    map<ll, vector<ll>> universities;
    for (i = 0; i < n; i++)
        cin >> u[i];
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        universities[u[i]].pb(s[i]);
    }

    int anss[n + 1] = {0};

    for (auto university : universities)
    {
        // clog << university.first << "-> ";
        vector<ll> &curStrengths = university.second;
        curStrengths.pb(0);
        int curStudents = curStrengths.size();
        sort(curStrengths.begin(), curStrengths.end());
        for (i = 1; i < curStudents; i++)
            curStrengths[i] += curStrengths[i - 1];
        for (int k = 1; k <= curStudents; k++)
        {
            // clog << k << " :" << (curStrengths[curStudents - 1] - curStrengths[curStudents % k]) << ", ";
            anss[k] += (curStrengths[curStudents - 1] - curStrengths[(curStudents - 1) % k]);
        }
        // clog << "\n";
    }

    for (int k = 1; k <= n; k++)
        cout << anss[k] << " ";

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
        // clog << "\nCase #\n";
        sol();
        cout << "\n";
    }
}
