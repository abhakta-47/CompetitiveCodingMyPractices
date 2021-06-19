#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int n;
vector<int> a, p;
int *cur_p;
void permute()
{
    int *cur = new int(n + 1);
    for (int i = 1; i <= n; i++)
        cur[p[i]] = i;
    // for (int i = 1; i <= n; i++)
    //     cout << i << "->" << cur[i] << ", ";
    delete[] cur_p;
    cur_p = cur;
}
void sol()
{
    cin >> n;
    a.reserve(n + 1);
    p.reserve(n + 1);
    cur_p = new int(n + 1);
    int i;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cur_p[i] = i;
    int q;
    cin >> q;
    while (q--)
    {
        int x, y, z;
        cin >> x;
        if (x == 1)
        {
            permute();
            // for (i = 1; i <= n; i++)
            //     cout << i << "->" << cur_p[i] << ", ";
            // cout << "\n";
            // for (i = 1; i <= n; i++)
            //     cout << i << "->" << a[i] << ", ";
            // cout << "\n";
            // for (i = 1; i <= n; i++)
            //     cout << i << "->" << a[cur_p[i]] << ", ";
        }
        else if (x == 2)
        {

            // for (i = 1; i <= n; i++)
            //     cout << i << "->" << a[i] << ", ";
            cin >> y >> z;
            y = cur_p[y];
            z = cur_p[z];
            int t = a[y];
            a[y] = a[z];
            a[z] = t;

            // for (i = 1; i <= n; i++)
            //     cout << i << "->" << a[i] << ", ";
        }
        else
        {
            cin >> y;
            // cout << cur_p[y] << "-";
            cout << a[cur_p[y]] << "\n";
        }
    }

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
        delete[] cur_p;
        // cout << "\n";
    }
}
