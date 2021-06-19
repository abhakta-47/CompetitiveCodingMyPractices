#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    int n;
    cin >> n;
    int a[n], i;
    int counts[2];
    set<int> count_diff;
    vector<pair<int, int>> ranges;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        counts[a[i]]++;
        if (counts[0] == counts[1])
            ranges.pb({});
        // count_diff.find()
    }
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
