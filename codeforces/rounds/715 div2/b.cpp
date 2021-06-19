#include <bits/stdc++.h>

using namespace std;

#define dout cout
#define ll long long
#define pb push_back

void sol(){
    ll n,i;
    cin>>n;
    string s;
    cin>>s;

    ll nt=0,nm=0;
    queue<ll>ts;
    for(i=0;i<n;i++){
        if(s[i]=='T'){
            ++nt;
            ts.push(i);
        }
        else{
            ++nm;
            if(ts.empty()){
                cout<<"NO";
                return;
            }
            // cout<<i<<"-"<<ts.top()<<", ";
            s[ts.front()]='t';
            ts.pop();
        }
    }
    
    queue<ll>ts2;
    for(i=n-1;i>=0;i--){
        if(s[i]=='T')
            ts2.push(i);
        else if(s[i]=='M'){
            if(ts2.empty()){
                cout<<"NO";
                return;
            }
            // cout<<i<<"-"<<ts2.top()<<", ";
            ts2.pop();
        }
    }

    if(ts2.empty())
        cout<<"YES";
    else
        cout<<"NO";

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    //t=1;
    cin >> t;
    while (t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
