#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	if( n%2 )
	    cout<<1<<" "<<n/2<<" "<<n/2;
	else
	    cout<<2<<" "<<n/2-1<<" "<<n/2-1;
	cout<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}