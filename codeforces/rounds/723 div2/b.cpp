#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

bool solution(int n)
{
    int a = 111, b = 11;
    // traverse for all possible values
    for (int i = 0; i * a <= n; i++)
    {

        // check if it is satisfying the equation
        if ((n - (i * a)) % b == 0)
        {
            // cout << "x = " << i << ", y = "
            //      << (n - (i * a)) / b;
            return true;
        }
    }

    return false;
}

void sol()
{
    int x;
    cin >> x;
    if (solution(x))
        cout << "YES";
    else
        cout << "NO";
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
