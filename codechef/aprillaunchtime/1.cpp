#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n, s;
    cin >> n >> s;
    int i, a[n], b[n];
    vector<pair<int, int> > v;

    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n; i++)
    {
        cin >> b[i];
        v.push_back( make_pair(a[i],b[i]) );
    }
    sort( v.begin(),v.end() );
    int x=v[0].first,y=v[0].second;
    bool flag=false;
    for(i=1;i<n;i++){
        if(v[i].second != y)
            {x+=v[i].first;flag=true;break;}
    }

    if( (s+x)<=100 && flag )
        cout<<"yes\n";
    else 
        cout<<"no\n";
    

}

int main()
{
    int t, i;
    cin >> t;
    for (i = 0; i < t; i++)
        func();
    return 0;
}
