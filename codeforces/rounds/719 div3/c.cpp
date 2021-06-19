#include<bits/stdc++.h>

using namespace std;

void sol(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return;
	}
	if(n==2){
		cout<<"-1\n";
		return;
	}
	int i;
	vector<int>a;
	for(i=1;i<=n*n;i+=2)
		a.push_back(i);
	for(i=2;i<=n*n;i+=2)
		a.push_back(i);
	for(i=0;i<n*n;i++){
		cout<<a[i]<<" ";
		if(i%n==n-1)
			cout<<"\n";
	}
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		sol();
		//cout<<"\n";
	}
}
