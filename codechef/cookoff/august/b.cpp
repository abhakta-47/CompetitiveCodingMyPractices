#include <iostream>
using namespace std;

string strMulti(int k, char c)
{
    string ans = "";
    for (int i = 0; i < k; i++)
        ans += c;
    return ans;
}

int func()
{
    int n, k;
    cin >> n >> k;
    int w[n], i, ans = 1, x, c=0;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x > k)
        {
            cout << -1;
            return 0;
        }
        if (c + x > k)
        {
            ++ans;
            c = 0;
        }
        c+=x;
    }
    cout << ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        func();
        cout << "\n";
    }
    return 0;
}
