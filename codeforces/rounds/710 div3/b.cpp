#include <bits/stdc++.h>

using namespace std;
int n,k;
string s;
int ans=0;
void findBefore(int x){

	cout<<x<<"-";

	if(x>=n)
		x=n-1;
	cout<<x<<" ";
	int ans=0;
	for(int i=x; i>=0; i--)
		if(s[i]=='*'){
			ans++;
			findBefore(i+k);
		}
}

void sol(){
	cin>>n>>k;
	cin>>s;
	ans=0;

	for(int i=0;i<n;i++){
		if( s[i]=='*'){
			s[i]='X';
			++ans;
			findBefore(i+k);
			break;
		}
	}

	cout<<ans;
	cout<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--)
		sol();
}