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
    string s;
    cin >> s;

    int i, c1 = 0, c0 = 0, x = n / k;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ++c1;
        else
            ++c0;
    }

    // if (x % 2) //odd
    // {

    //     int sn0 = c0 / (x - 1);
    //     int sn1 = c1 / (x - 1);
    //     if(sn0+sn1!=k){
    //         cout << "IMPOSSIBLE";
    //         return 0;
    //     }

    //     for (i = 1; i < x; i++){
    //         if (i % 2)
    //             cout << (strMulti(sn0, '0') + strMulti(sn1, '1'));
    //         else
    //             cout << (strMulti(sn1, '1') + strMulti(sn0, '0'));
    //             cout<<" ";}
    //     cout << (strMulti(c0 % (x - 1), '0') + strMulti(c1 % (x - 1), '1'))<<"   ";
    // }
    // else //even
    // {

    if (c0 % x || c1 % x)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    else
    {
        for (i = 1; i <= x; i++)
            if (i % 2)
                cout << (strMulti(c0 / x, '0') + strMulti(c1 / x, '1'));
            else
                cout << (strMulti(c1 / x, '1') + strMulti(c0 / x, '0'));
    }
    // }
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
