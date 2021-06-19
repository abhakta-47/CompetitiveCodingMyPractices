#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool checkValidity(string &s){
    // cout<<"checkValidity"<<s<<"\n";
    if(s.empty())
        return false;

    int c1=0,c0=0;
    for(int i=0;i<s.length();i++)
        if(s[i]=='0')
            ++c0;
        else
            ++c1;

    return( c0==c1 ? true : false);
}

void sol(){
    int n;
    string a,b;
    cin>>n>>a>>b;

    int i;
    string tmp;
    bool same=(a[0]==b[0]);
    for(i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(same){
                if(!checkValidity(tmp)){
                    cout<<"NO";
                    return;
                }
                tmp.clear();
                same=false;
            }
            tmp+=a[i];
        }
        else{
            if(!same){
                if(!checkValidity(tmp)){
                    cout<<"NO";
                    return;
                }
                tmp.clear();
                same=true;
            }
            tmp+=a[i];
        }
    }
    if(!same)
        if(!checkValidity(tmp)){
            cout<<"NO";
            return;
        }
    cout<<"YES";
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
