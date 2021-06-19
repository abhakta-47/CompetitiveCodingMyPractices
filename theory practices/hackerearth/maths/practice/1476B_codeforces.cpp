#include <bits/stdc++.h>

using namespace std;

int func(){
    long long n,k;
    cin >> n >> k;
    long long p[n], i;
    for(i=0; i<n; i++)
        cin >> p[i];

    long long s=p[0], ans=0;
    for(i=1; i<n; i++){
        long double inflation=p[i]*1.0/s;
        // cout << i <<" -> "
        //      << inflation << " " 
        //      << (k*1.0/100) << "\n";
        if(inflation > (k*1.0/100)){
            long long x= ceil( (100*p[i] - k*s)*1.0/k );
            ans += x;
            s += x;
        }

        s += p[i];
    }

    cout << ans;


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
