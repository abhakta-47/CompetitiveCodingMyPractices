#include <bits/stdc++.h>
using namespace std;

#define ll long long

// void visible_range(int l, int r, int *h, int x){
// 	int r=0,c=0;
// 	while(i<n){

// 	}
// }

void sol(){
	int n;
	cin>>n;
	int h[n], i;
	for(i=0;i<n;i++)
		cin>>h[i];

	int c[n];

	for(i=0;i<n;i++){
		c[i]=0;

		for(int j=i+1; j<n; j++)
			if(h[i]<h[j])
				break;
			else if(h[i]==h[j])
				++c[i];

	}

	int c_tmp[n];
	for(i=n-1; i>=0; i--){
		c_tmp[i]=0;

		for(int j=i-1; j>=0; j--)
			if(h[i]<h[j])
				break;
			else if(h[i]==h[j])
				++c_tmp[i];

	}

	for(i=0;i<n;i++)
		cout<<max(c[i], c_tmp[i])<<" ";

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