#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	int a[n], i, noMod[m]={0};
	for(i=0;i<n;i++){
		cin>>a[i];
		a[i] %= m;
		noMod[a[i]]++;
	}
	noMod[0]=( noMod[0]? 1 : 0);
	int ans=0;
	for(i=1;i<=m/2;i++){
		// cout<<i<<" "
		// 	<<noMod[i]<<" "
		// 	<<noMod[m-i]<<" ";
		int _max=max( noMod[i], noMod[m-i]);
		int _min=min( noMod[i], noMod[m-i]);
		if( _max==0)
			ans+=0;
		else if( _min==0 )
			ans+=_max;
		else if(_max-_min<=1)
			ans+=1;
		else
			ans+=_max-_min;
	}
	cout<<ans+noMod[0]<<"\n";

}

int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}