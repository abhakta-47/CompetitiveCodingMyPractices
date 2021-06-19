#include <bits/stdc++.h>

using namespace std;

int func(){
    int c;
    cin >> c;
    // int cLength=ceil(log2(c));
    vector<int>x[2];
    int i;
    while(c){
        // cout<<c%2;
        if(c%2){
            x[0].push_back(0);
            x[1].push_back(1);
        }
        else{
            x[0].push_back(1);
            x[1].push_back(1);
        }
        
        c/=2;
    }
    // cout<<"\n";
    x[0][ x[0].size()-1 ]=1; x[1][ x[0].size()-1 ]=0;

    // for(i=0; i<x[0].size(); i++)
        // cout << x[0][i];
    // cout<<"\n";
    // for(i=0; i<x[0].size(); i++)
        // cout << x[1][i];
    // cout<<"\n";

    long x0=0, x1=0;
    for(i=0; i<x[0].size(); i++){
        x0 += long(x[0][i])*( long(1)<<i);
        x1 += long(x[1][i])*( long(1)<<i);
    }

    // cout << x0 << " " << x1 << " " <<x0*x1;
    cout << x0*x1;

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
        //// cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
