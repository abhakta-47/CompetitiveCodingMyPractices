#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	cout<<n/2<<" "
		<<n/2<<" ";
	for(i=1;i<=k-2;i++)
		cout<<1<<" ";
	cout<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}