#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    cout << ( n%2==0 ? (n/2+1)*(n/2+1) : 2*(n/2+1)*(n/2+2) );
}
