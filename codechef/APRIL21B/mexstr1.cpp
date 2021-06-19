#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN=(int)1e6;
int dp[MAXN+2],dp_1[MAXN+2];
int next_0[MAXN],next_1[MAXN];

void sol(){
	string s;
	cin>>s;
	int n=s.length();

	// next 0
	int lastPOs=-1;
	for(int i=0;i<n;i++){
		if(s[i] == '0'){
			for(int j=lastPOs+1;j<=i;j++)
				next_0[j]=i;
				lastPOs=i;
			
		}
	}
	for(int i=lastPOs+1;i<n;i++)
		next_0[i]=n;
	// all 1 case 
	if(next_0[0] == n){
	   cout<<"0";
	    return ;
	}

	// next 1
	lastPOs=-1;
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			for(int j=lastPOs+1;j<=i;j++)
				next_1[j]=i;
				lastPOs=i;
			
		}
	}	
	for(int i=lastPOs+1;i<n;i++)
		next_1[i]=n;
	
	
	// dp
	dp[n]=dp[n+1]=0;
	dp_1[n]=dp_1[n+1]=0;
	
	for(int i=n-1;i>=0;--i){
		dp[i]=dp[i+1];
		if(s[i] == '0' && next_1[i] < n)
			dp[i]=max(dp[i],dp[next_1[i]+1]+1);
		if(s[i] == '1' && next_0[i] <n)
		    dp[i]=max(dp[i],dp[next_0[i]+1]+1);		
		dp_1[i]=dp_1[i+1];
		if(next_1[i] < n)
			dp_1[i]=max(dp_1[i],dp[next_1[i]+1]+1);
		
	}
	
	int len=dp_1[0]+1;
	int curind=next_1[0]+1;
	string ans="1";
	for(int i=1;i<len;++i)
	{
		if(curind >= n){
			ans.push_back('0');
			continue;
		}
		if(next_0[curind] >= n){
		    ans.push_back('0');
		    curind=next_0[curind]+1;
		    continue;
		}
		if(dp[next_0[curind]+1] <len-i-1){
			ans.push_back('0');
			curind=next_0[curind]+1;
		}else{
			ans.push_back('1'); //third change
			curind=next_1[curind]+1;

		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		sol();
		cout<<"\n";
	}
}