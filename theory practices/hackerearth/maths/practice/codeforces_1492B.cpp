#include <bits/stdc++.h>

using namespace std;

void func(){
	int n;
	cin >> n;
	int p[n];
	for(int i=0;i<n;i++)
		cin >> p[i];
	stack<int>s;
	int maxP=0;
	for(int i=0;i<n;i++)
		if(p[i]>maxP){
			s.push(i);
			maxP=p[i];
		}
	int tr,r=n;
	while(!s.empty()){
		// cout << " |"<<s.top()<<" - ";
		tr=s.top();
		s.pop();

		for(int i=tr; i<r; i++)
			cout << p[i] << " ";

		r=tr;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
