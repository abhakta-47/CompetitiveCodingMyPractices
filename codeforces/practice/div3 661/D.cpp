#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int func()
{

    int n;
    string s;
    cin >> n >> s;

    int i, ans[n], k = 1;
    queue<int> q0, q1;

    ans[0] = 1;

    for (i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            if (s[i - 1] == '1')
                q1.push(ans[i - 1]);
            else
                q0.push(ans[i - 1]);

            if (s[i] == '1')
            {
                if (q0.empty())
                    ans[i] = ++k;
                else
                {
                    ans[i] = q0.front();
                    q0.pop();
                }
            }
            else
            {
                if (q1.empty())
                    ans[i] = ++k;
                else
                {
                    ans[i] = q1.front();
                    q1.pop();
                }
            }
        }
        else
            ans[i] = ans[i - 1];
    }

    cout << k << "\n";
    for (i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    //t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
