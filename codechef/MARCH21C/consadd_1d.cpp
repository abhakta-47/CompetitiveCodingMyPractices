#include <bits/stdc++.h>
using namespace std;

int x=3;

void consAdd1d(int *a, int n){
	int carry=0;
	queue<int>q;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<"\n";

	for(int i=0; i<n; i++){
		cout<<a[i]<<" -> "
			<<a[i]-carry<<"pushed ";
		q.push(a[i]-carry);
		if(i >= x){
			cout<<carry<<" decreasedby "
					<<q.front()<<" to ";
			carry -= q.front();
			q.pop();
			cout<<carry<<" ";
		}
		if(i<=n-x)
			carry += a[i]-carry;
		cout<<carry;
		a[i] -= carry;
		cout<<"\n";
	}

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

int main(){

	int a[]={0,1,1,1,0};
	consAdd1d(a, 5);

	// int b[]={1,2,1}; x=2;
	// consAdd1d(b,3);

	// int c[]={1,7,8,10,5,1}; x=4;
	// consAdd1d(c,6);

	cout<<"\n";
}