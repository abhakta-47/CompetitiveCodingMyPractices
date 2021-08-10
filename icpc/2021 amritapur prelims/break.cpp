#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll q = 0;
    cin >> q;
    ll ans = 0;
    ll merge = 0;
    while (q--)
    {
        int n = 0;
        cin >> n;
        merge += n;
        int arr[n] = {0};
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int i;
        vector<int> temp;
        vector<int> vec;
        for (i = 0; i < n; i++)
        {

            if (arr[i] <= arr[i + 1])
            {
                temp.pb(arr[i]);
            }
            else
            {
                temp.pb(arr[i]);
                vec.pb(temp.size());
                temp.clear();
            }
        }
        // vec.pb(temp.size());
        for (auto x : vec)
        {
            cout << x << ", ";
        }
        cout << "\n";
        sort(vec.begin(), vec.end());
        for (int j = 0; j < vec.size() - 1; j++)
        {
            ans += vec[j];
        }
    }
    ans += merge;
    cout << ans << endl;
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
