#include <bits/stdc++.h>

using namespace std;

int specialMod(int n, int m){
    return ( n%m ? n%m : m );
}

int func(){
    int n,kH;
    cin>>n>>kH;

    if(n%2==0){
        cout << specialMod(kH, n);
        return 0;
    }

    // n%2!=0  odd
    --kH;
    cout << ( kH+ (n%2)*(kH/(n/2)) )%n + 1;

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
