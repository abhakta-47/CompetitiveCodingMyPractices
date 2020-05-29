// CPP program to find the
// blocks for given number.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v, v1;
    for (int i = 0; i <= 5; i++)
    {
        v.push_back(i);
    }
    //v.resize(5, 1);
    v.resize(7, 2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}
