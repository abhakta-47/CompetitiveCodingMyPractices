#include <bits/stdc++.h>

using namespace std;

int func(){

    int n,q,k;
    cin >> n>>q>>k;
    int i, a[n+2];
    a[0]=0; a[n+1]=k+1;
    for(i=1;i<=n;i++)
        cin>>a[i];

    int p[n+2]={0};
    for(i=1;i<=n;i++)
        p[i]= (a[i+1]-a[i-1]-2) + p[i-1];

    int l,r;
    for(i=1;i<=q;i++){
        cin >> l >> r;
        cout << p[r] - p[l-1] + (k+1-a[r+1]) + (a[l-1])
            <<"\n";
    }



	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin>>t;
    // while(t-->0)
        func();
}
