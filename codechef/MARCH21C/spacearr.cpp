#include <bits/stdc++.h>

using namespace std;

int func(){
    int n;
    cin>>n;
    int a[n], i;
    for(i=0;i<n;i++)
        cin>>a[i];

    sort(a, a+n);
    long k=0;
    for(i=0;i<n;i++){

        if( a[i]>i+1 ){
            cout<<"Second";
            return 0;
        }

        k += long(i+1-a[i]);
    }

    if(k%2)
        cout << "First";
    else
        cout << "Second";

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
