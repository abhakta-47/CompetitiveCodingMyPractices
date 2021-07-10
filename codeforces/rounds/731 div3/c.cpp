#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{

    int k, n, m;
    cin >> k >> n >> m;
    queue<int> a, b;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        b.push(x);
    }
    int kc = k;
    vector<int> ans;
    // while (!a.empty() || !b.empty())
    // {
    //     if (a.front() > k)
    //     {
    //         while (!b.empty() || b.front() == 0)
    //         {
    //             ans.push_back(b.front());
    //             b.pop();
    //         }
    //     }
    //     else if (b.front() > k)
    //     {
    //         while (!a.empty() || a.front() == 0)
    //         {
    //             ans.push_back(a.front());
    //             a.pop();
    //         }
    //     }
    // }
    int tr = 0;
    while (true)
    {
        // cout << k << " " << a.size() << b.size() << " " << a.front() << b.front() << "\n";
        if (!a.empty())
            if (a.front() == 0)
            {
                // cout << "#" << a.front() << a.empty() << " ";
                while (a.front() == 0 && !a.empty())
                {
                    ans.push_back(a.front());
                    ++k;
                    // cout << k << ".";
                    a.pop();
                }
            }
            else if (a.front() <= k)
            {
                ans.push_back(a.front());
                a.pop();
            }
            else
            {
                if (b.front() > k || b.empty())
                {
                    cout << "-1";
                    return;
                }
            }

        if (!b.empty())
            if (b.front() == 0)
            {
                while (b.front() == 0 && !b.empty())
                {
                    ans.push_back(b.front());
                    // cout << k << ".";
                    ++k;
                    b.pop();
                }
            }
            else if (b.front() <= k)
            {
                ans.push_back(b.front());
                b.pop();
            }
            else
            {
                if (a.front() > k || a.empty())
                {
                    cout << "-1";
                    return;
                }
            }

        if (a.empty() && b.empty())
            break;
        // for (auto iv : ans)
        //     cout << iv << " ";
        // cout << "\n";
        ++tr;
        if (tr > n + m)
        {
            cout << "-1";
            return;
        }
    }

    for (auto iv : ans)
        cout << iv << " ";
    return;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
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
