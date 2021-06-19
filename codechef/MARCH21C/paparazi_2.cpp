#include <bits/stdc++.h>

using namespace std;

class Mountain{
public:
	int x, h;
	Mountain(){
		x=0; h=0;
	}
	Mountain(int x, int h){
		this->x=x;
		this->h=h;
	}
	void setMountain(int x, int h){
		this->x=x;
		this->h=h;
	}
};

double inclination(Mountain *m1, Mountain *m2){
	// cout<<" ("<<m2->h<<"-"<<m1->h<<"/"<<m2->x<<"-"<<m1->x<<")  ";
	// return 0;
	return ( (m2->h-m1->h)*1.0/(m2->x-m1->x) );
}

void biggerList(vector<Mountain *>&v, int n, Mountain **h){
	Mountain *temp=h[0];
	v.clear();
	for(int i=0;i<n;i++)
		if( h[i]->h >= temp->h ){
			v.push_back(h[i]);
			temp = h[i];
		}
}

int maxDis(Mountain **h, int n, vector<Mountain *>&v){
	int i;

	int ans=0;
	for( i=0; i<v.size(); i++){
		int j=i+1;
		double maxInclination=-INFINITY;
		// cout<<v[i]->x<<" "<<v[i]->h<<"->\n";
		for( j=i+1; j<v.size(); j++){
			double currInclinaion = inclination( v[i], v[j]);
			// cout<<v[j]->x<<" "<<v[j]->h<<" "<<currInclinaion;
			if( currInclinaion >= maxInclination){
				ans = max(ans, ( v[j]->x>v[i]->x ?  v[j]->x-v[i]->x : v[i]->x-v[j]->x));
				// cout<<" "<<ans;
				maxInclination = currInclinaion;
			}
			// cout<<"\n";
		}
		// cout<<"\n";
	}
	// cout<<"ans    "<<ans<<"\n";

	return ans;
}

void func(){
	int n;
	cin>>n;
	int i, x;
	Mountain *h[n];
	for(i=0;i<n;i++){
		cin>>x;
		Mountain* tmp=new Mountain(i,x);
		h[i]=tmp;
	}
	
	vector<Mountain * >v;
	v.push_back(h[0]);
	v.push_back(h[1]);
	int ans=1;
	for(i=2;i<n;i++){
		while( v.size()>=2 ){
			double s1=inclination( v[v.size()-1], v[v.size()-2] );
			double s2=inclination( h[i], v[v.size()-1] );
			if( s1<=s2 )
				v.pop_back();
			else
				break;
		}
		v.push_back(h[i]);
		ans=max(ans, v[ v.size()-1 ]->x- v[ v.size()-2 ]->x );
	}
	cout<<ans<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--)
		func();
}