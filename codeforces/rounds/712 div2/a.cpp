#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool notPalindrome(string s){
    int i,n=s.length();
    for(i=0;i<n/2;i++)
        if(s[i]!=s[n-i-1])
            return true;

    return false;
}

void sol(){
    string s;
    cin>>s;
    if( notPalindrome('a'+s))
        cout<<"YES\na"+s;
    else if( notPalindrome(s+'a'))
        cout<<"YES\n"+s+'a';
    else
        cout<<"NO";

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
