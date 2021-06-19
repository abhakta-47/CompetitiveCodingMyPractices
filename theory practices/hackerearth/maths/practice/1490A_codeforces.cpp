#include <bits/stdc++.h>

using namespace std;

int func(){
    int n, i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    int ans=0;
    for(i=0;i<n-1;i++){
        // cout << "\n" << a[i] <<" "<<a[i+1]<<" ";
        double x=max(a[i],a[i+1])*1.0/min(a[i],a[i+1]);
        // cout << x <<" ";
        if( x <=2 )
            continue;
        x=log2(x);
        // cout << x <<" "<<ceil(x-1);
        ans += ceil(x-1);
    }
    // cout << "\nans::";
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
