#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define limit 1000000000
ll x, y, l;
string s;
ll j;
pair<ll, ll> temp;
pair<ll, ll> move(ll n)
{

    ll xt = 0, yt = 0;

    //cout << " *" << n << " * " << p << "      ";
    while (j < l)
    {
        xt %= limit;
        yt %= limit;

        if (s[j] == 'N')
            --yt;
        else if (s[j] == 'S')
            ++yt;
        else if (s[j] == 'E')
            ++xt;
        else if (s[j] == 'W')
            --xt;
        else if (s[j] == ')')
        {

            cout << " boxy " << xt << " " << yt << " ";
            xt *= n;
            yt *= n;
            ++j;
            cout << " oxy " << xt << " " << yt << " ";
            return make_pair(xt, yt);
            //return j;
        }
        else
        {
            // x += n * xt;
            // y += n * yt;
            ll t = int(s[j]) - 48;
            cout << " xy " << xt << " " << yt << " ";
            j += 2;
            temp = move(t);
            xt += temp.first;
            yt += temp.second;
            cout << " *xy " << xt << " " << yt << " ";
        }
        ++j;
    }
}

int func()
{
    x = 0;
    y = 0;
    cin >> s;
    if (48 <= s[0] && s[0] <= 57)
    {
        j = 2;
        l = s.length();
        move(s[0]);
    }
    else
    {
        j = 0;
        s = s + ')';
        l = s.length();
        move(1);
    }

    s = s + ")";
    j = 0;
    //cout << s << s.length();
    temp = move(1);
    x = temp.first;
    y = temp.second;
    // x %= limit;
    // y %= limit;

    //cout << "      " << x << " " << y << " ";

    if (x >= 0)
        x %= limit;
    else
    {
        x = ((-1) * ++x);
        x %= l;
        x = l - (++x);
    }

    if (y >= 0)
        y %= limit;
    else
    {
        y = (-1) * (++y);
        y %= limit;
        y = limit - y - 1;
    }

    //x %= limit;
    //y %= limit;

    cout << "ans2 " << x + 1 << " " << y + 1;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}