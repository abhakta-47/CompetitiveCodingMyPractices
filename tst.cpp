#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define ll long long
#define pb push_back

time_t start,end;
float elapsed=0;

void timerStart(){
	if(start==NULL && end==NULL)
		start=time(NULL);
	
	start=time(NULL);
}

void timePause(){
	end=time(NULL);
	elapsed+=difftime(end,start);
}


void sol()
{

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	//t=1;
	cin >> t;
	while (t--)
	{
		//cout<<"Case #"<<i+1<<": ";
		sol();
		cout << "\n";
	}
}
