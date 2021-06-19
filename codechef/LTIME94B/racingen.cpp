#include <bits/stdc++.h>
using namespace std;

#define ll long long

void sol(){
	ll x,r,m;
	cin>>x>>r>>m;

	r=r*(ll)60;
	m=m*(ll)60;
	ll t;
	if(r<=x)
		t=r;
	else{
		t=x;
		r-=x;
		t+=r*2;
	}

	if(t<=m)
		cout<<"YES";
	else
		cout<<"NO";

	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
		sol();
}