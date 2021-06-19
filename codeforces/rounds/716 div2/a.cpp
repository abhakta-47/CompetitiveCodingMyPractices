#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

#define mem(x,y) memset(x,y,sizeof(x))

#define loop(n) for(int i=0;i<n;i++)
#define listInput(l,n) for(int i=0;i<n;i++) cin>>l[i];

bool isPerfectSquare(int x)
{
    if (x >= 0) {
 
        int sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

void sol(){
    int n;
    cin>>n;
    int i,a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++){
        if( !isPerfectSquare(a[i]) ){
            cout<<"YES";
            return;
        }
    }
    cout<<"YES";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,i;
    cin>>t;
    // t=1;
    while(t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
