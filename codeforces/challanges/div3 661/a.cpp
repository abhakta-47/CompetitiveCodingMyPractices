#include <bits/stdc++.h>

using namespace std;

int func()
{
    int n;
    cin >> n;
    int i, x;
    set<int> s;
    set<int>::iterator its;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    if (n == 1)
    {
        cout << "YES";
        return 0;
    }
    bool f = true;
    for (its = s.begin(); its != s.end(); its++)
    {
        if (*(++its) - *(--its) > 1)
        {
            f = false;
            break;
        }
    }

    if (f)
        cout << "YES";
    else
        cout << "NO";

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
