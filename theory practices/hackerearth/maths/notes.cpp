#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

// naumber theory - 1

// Modular arithmetic
// Modular exponentiation
// Greatest Common Divisor (GCD)
// Extended Euclidean algorithm
// Modular multiplicative inverse

ll gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll binaryExp(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //n is even
        return binaryExp(x * x, n / 2);
    else //n is odd
        return x * binaryExp(x * x, (n - 1) / 2);
}

ll binaryExp(int x, int n, int &M) // binaryExp with mod
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //n is even
        return binaryExp((x * x) % M, n / 2, M);
    else //n is odd
        return (x%M * binaryExp((x * x) % M, (n - 1) / 2, M)%M) % M;
}

inline ll modAdd(int x, int y, int m){	
    return ((x % m) + (y % m)) % m;
}

inline ll modMultiply(int x, int y, int m){
    return ((x % m) * (y % m)) % m;
}

inline ll modSubtract(int x, int y, int m){
    return ((x % m) - (y % m) + m) % m;
}

ll modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    int res = (x % m + m) % m;
    return res;
}

ll modDivide(int x, int y, int m)
{
    return ((x % m) * (modInverse(y, m) % m) % m);
}

//main
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << binaryExp(15,3);
    // int t, i;
    // //t=1;
    // cin >> t;
    // for (i = 0; i < t; i++)
    // {
    //     //cout<<"Case #"<<i+1<<": ";
    //     func();
        cout << "\n";
    // }
}
