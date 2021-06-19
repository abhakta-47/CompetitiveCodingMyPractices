#include <bits/stdc++.h>
using namespace std;

#define ll long long

void sol(){
	int a,y,x;
	cin>>a>>y>>x;
	if(y<=a)
	    cout<<(ll)y*(ll)x;
	else
	    cout<<(ll)a*(ll)x+(ll)1;

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