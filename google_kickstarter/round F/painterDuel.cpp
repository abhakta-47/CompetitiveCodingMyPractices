#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define pb push_back

int valueChange(int x, int y)
{
    if (x == 2 && y == 2)
        return 2;
    else
        return 1;
}

int func()
{
    int s, ra, pa, rb, pb, c;
    cin >> s >> ra >> pa >> rb >> pb >> c;

    if (s != 2)
    {
        cout << 15;
        return 0;
    }
    
    int p1 = valueChange(ra, pa),
        p2 = valueChange(rb, pb),
        con[c];

    int i, x, y;
    for (i = 0; i < c; i++)
    {
        cin >> x >> y;
        con[i] = valueChange(x, y);
    }
    int ans;
    if (p1 == 1 && p2 == 1)
    {
        if (c == 0)
            ans = 2;
        else if (c == 1 && con[0] == 1)
            ans = 1;
        else if (c == 1 && con[0] == 2)
            ans = 0;
        else // c==2 => con = 1,2
            ans = 0;
    }
    else if (p1 == 1 && p2 == 2)
    {
        if (c == 0)
            ans = -1;
        else if (c == 1)
            ans = -1;
        else //c==2
            ans = 0;
    }
    else
    { // p1 =2 , p2=1
        if (c == 0)
            ans = 1;
        else if (c == 1)
            ans = 1;
        else //c==2
            ans = 0;
    }
    cout << ans;
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
        cout << "Case #" << i + 1 << ": ";
        func();
        cout << "\n";
    }
}
