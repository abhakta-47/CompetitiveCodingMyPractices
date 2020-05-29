#include <bits/stdc++.h>
using namespace std;

int func(){
    int n;
    cin>>n;
    int i, k=1, x;
    map<int,int> m;
    int y;
    cin>>x;
    bool flag = true;
    for(i=1;i<n;i++){
        cin>>y;
        if(y != x){
            if( m.find(x) != m.end() )
                flag = false;
            else
               {
                   m.insert( make_pair(x,k) );}
            k = 1;
        }
        x = y;
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(--t>=0)
	    func();
	return 0;
}
