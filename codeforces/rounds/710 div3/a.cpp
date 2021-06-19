#include <bits/stdc++.h>

using namespace std;

void sol(){
	long long n,m,x;
	cin>>n>>m>>x;
	// x= c-1*n + r
	// x= r-1*m + c
	// x%n+1 row
	// x/m+1 col
	--x;
	long long r = x%n;
	long long c = x/n;
	// cout<<r<<" "<<c<<" ";
 	cout << r*m +c + (long long)1;
	cout<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--)
		sol();
}