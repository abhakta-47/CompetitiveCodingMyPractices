#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sol(){
    int a,b;
    cin>>a>>b;
    int ca=a, cb=b, n=a+b;
    string s;
    cin>>s;

    // n odd n/2 ?
    int na=0, nb=0, nc=0;
    for(int i=0;i<n/2;i++){
        char c1=s[i], c2=s[n-1-i];
        if(c1==c2){
            switch(c1){
                case '0': a-=2; break;
                case '1': b-=2; break;
                case '?': nc+=2; break;
            }
        }
        else if( c1=='?'){
            switch(c2){
                case '0': a-=2; s[i]=c2; break;
                case '1': b-=2; s[i]=c2; break;
            }
        }
        else if(c2=='?'){
            switch(c1){
                case '0': a-=2; s[n-1-i]=c1; break;
                case '1': b-=2; s[n-1-i]=c1; break;
            }   
        }
        else{
            cout<<-1;
            return;
        }

        if(a<0 || b<0){
            cout<<-1;
            return;
        }
    }

    if(n%2){
        switch(s[n/2]){
            case '0': a-=1; break;
            case '1': b-=1; break;
            case '?': nc+=1; break;
        }
    }

    for(int i=0;i<n/2;i++){
        char &c1=s[i], &c2=s[n-1-i];
        if(c1==c2 && c1=='?')
            if(a>1){
                c1='0';c2='0';
                a-=2;
            }
            else if(b>1){
                c1='1';c2='1';
                b-=2;
            }
            else{
                cout<<-1;
                return;
            }
    }

    if( n%2 && s[n/2]=='?' ){
        if(a>0){
            s[n/2]='0';
            --a;
        }
        else if(b>0){
            s[n/2]='1';
            --b;
        }
        else{
            cout<<-1;
            return;
        }
    }

    if(a==0 && b==0)
        cout<<s;
    else{
        cout<<"-1";
        return;
    }

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