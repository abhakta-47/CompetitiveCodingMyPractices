#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sol(){
        int n;
        cin>>n;
	int x, i;
	map<int,int>m;
	for(i=0;i<n;i++){
		cin>>x;
		++m[x-i];	
	}
	ll ans=0;
	for(auto im:m){
		x=im.second;
		ans+=(ll)x*(x-1)/2;
	}
	cout<<ans;
}

int main(){
        int t;
        cin>>t;
        while(t--){
                sol();
                cout<<"\n";
        }
}
