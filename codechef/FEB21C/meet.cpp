// https://www.codechef.com/FEB21C/problems/MEET
// done :)

#include <bits/stdc++.h>
using namespace std;

#define dout cout

string formatter(int x)
{
    string s = to_string(x);
    if (s.length() == 1)
        return "0" + s;
    else
        return s;
}

map<string, int> time2int;

void map_builder()
{

    string am = "AM";
    int h = 12, m, k = 0;

    for (m = 0; m < 60; m++)
        time2int.insert({formatter(h) + ":" + formatter(m) + " " + am, k++});
    for (h = 1; h < 12; h++)
        for (m = 0; m < 60; m++)
            time2int.insert({formatter(h) + ":" + formatter(m) + " " + am, k++});

    h = 12;
    am = "PM";
    for (m = 0; m < 60; m++)
        time2int.insert({formatter(h) + ":" + formatter(m) + " " + am, k++});
    for (h = 1; h < 12; h++)
        for (m = 0; m < 60; m++)
            time2int.insert({formatter(h) + ":" + formatter(m) + " " + am, k++});
}

int func()
{
    string p;
    getline(cin, p);
    //dout << p << "\n";
    int n, p_time = time2int[p];
    cin >> n;
    cin.ignore();
    string s, tr[2][n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        tr[0][i] = s.substr(0, 8);
        tr[1][i] = s.substr(9, 8);
        // cout << s << " - " << tr[0][i] << " |" << tr[1][i] << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        // tr0 <= p <= tr1
        // tr0,p <=0    p,tr1 <= 0
        //dout << tr[0][i] << "   " << tr[1][i] << "\n";
        //dout<<time2int[tr[0][i]]-p_time<<"  "<<time2int[tr[1][i]]-p_time<<"\n";
        if ((time2int[tr[0][i]] - p_time) <= 0 && (time2int[tr[1][i]] - p_time) >= 0)
            cout << 1;
        else
            cout << 0;
        //dout << "\n\n";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    // t = 1;
    cin >> t;
    cin.ignore();
    map_builder();
    for (i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        func();
        // cout << "case out";
        cout << "\n";
    }
}