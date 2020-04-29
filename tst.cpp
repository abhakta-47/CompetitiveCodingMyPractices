// CPP program to find the
// blocks for given number.
#include <bits/stdc++.h>
using namespace std;

void block(long int x)
{
    vector<long int> v;

    // Converting the decimal number
    // into its binary equivalent.
    cout << "Blocks for " << x << " : ";
    while (x > 0)
    {
        v.push_back(x % 2);
        x = x / 2;
    }

    // Displaying the output when
    // the bit is '1' in binary
    // equivalent of number.
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            cout << i;
            if (i != v.size() - 1)
                cout << ", ";
        }
    }
    cout << endl;
}

// Driver Function
int main()
{
    // map<int, int> m;
    // map<int, int>::iterator itm;

    // m.insert(make_pair(1, 2));
    // //cout << m.size() << " " << m.begin()->second << "   ";
    // //m.erase(1);
    // m.insert(make_pair(2, 3));
    // //cout << m.size() << " " << m.begin()->second;

    // for (itm = m.begin(); itm != m.end(); itm++)
    //     cout << itm->second;

    set<int> v1, v2;

    v1.insert(1);
    v1.insert(2);
    v2.insert(1);
    v2.insert(2);
    //v1 = v2;
    if (v1 == v2)
        cout << "yes";
    else
        cout << "no";
    // cout << upper_bound(v.begin(), v.end(), 4) - v.begin() << " ";
    // cout << v.end() - lower_bound(v.begin(), v.end(), 2);

    //cout << floor(5 * 1.0 / 3);

    //cout<<s.lower_bound(2)-s.begin();
}
