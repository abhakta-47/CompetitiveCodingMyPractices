#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sol(){
    int n;
    string s;
    cin>>n>>s;

    if(s[0]=='0' || s[n-1]=='0'){
        cout<<"NO";
        return;
    }

    string a,b;
    for(int i=0;i<n;i++){
        cout<<i<<"->\n";
        if(i<n-1){            
            if( s[i]=='0' && s[i+1]=='0' ){
                // cout<<".";
                // cout<<s[i]<<s[i+1]<<" ";
                a+="()";
                b+=")(";
                ++i;
                cout<<a<<'\n'<<b<<"\n";
                continue;
            }
        }

        a+=( i<n/2 ? '(' : ')' );
        b+=( s[i]=='1' ? a[i] : ( i<n/2 ? ')' : '(' ));
        
        cout<<a<<'\n'<<b<<"\n";
    }
    cout<<"\n";
    cout<<a<<'\n'<<b;
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
