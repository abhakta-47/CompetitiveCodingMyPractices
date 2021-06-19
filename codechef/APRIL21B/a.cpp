#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define pb push_back;

vector<string>binaries;

// Returns true if s1 is substring of s2
bool isSubSequence(string str1, string str2)
{	
	ll m=str1.length();
	ll n=str2.length();
    ll j = 0; // For index of str1 (or subsequence
 
    // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1
    for (ll i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == m);
}

string int2binStr(ll x){
	if(x==0)
		return "0";
	string s;
	while(x){
		s= (x%2?'1':'0')+s;
		x/=2;
	}
	return s;
}

void speicalPrint(string s){
	cout<<s;
		// for(ll j=0;j<s.size();j++){
		// 	cout<<s[j];
		// 	if(j%4==3)
		// 		cout<<" ";
		// }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll limit=1000000;
	for(ll i=0;i<=limit;i++)
		binaries.push_back(int2binStr(i));
	// for(ll i=0;i<=limit;i++){
	// 	for(ll j=0;j<binaries[i].size();j++)
	// 		cout<<binaries[i][j];
	// 	cout<<"\n";
	// }
	for(ll i=0;i<=limit;i++){
		// speicalPrint(binaries[i]);
		// cout<<"->\n";
		for(ll j=0;j<limit;j++){
			if(!isSubSequence(binaries[j], binaries[i])){
				// cout<<binaries[j];
				speicalPrint(binaries[j]);
				break;
			}
		}
		cout<<"\n";
	}

    return 0;
}