#include <bits/stdc++.h>

using namespace std;

int func(){
    int n;
    cin>>n;
    int i, a[n],c[3]={0};
    for(i=0;i<n;i++){
        cin >> a[i];
        ++c[ a[i]%3 ];
    }

    int ans=0;
    while( true ){
        for(i=0;i<3;i++){
            if(c[i]>n/3){
                --c[i];
                ++c[ (i+1)%3 ];
                ++ans;
            }

        if( min( min(c[0], c[1]), c[2]) ==n/3 )
            break;
        }       
        if( min( min(c[0], c[1]), c[2]) ==n/3 )
            break;
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
