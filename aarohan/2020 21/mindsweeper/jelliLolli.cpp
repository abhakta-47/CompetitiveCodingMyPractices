#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long

ll balance=12345678910;


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    ll sherTotal, mycTotal, x, y, ans=(ll)0;

    for(x=(ll)2;x<balance/(ll)11;x+=(ll)2){
        cout<<x<<"->\n";
        for(y=(ll)2;y<balance/(ll)5;y+=(ll)2){
            sherTotal=(ll)7*x+(ll)5*y;
            mycTotal=(ll)11*x+(ll)2*y;
            if( sherTotal>balance || mycTotal>balance )
                break;
            if( sherTotal%mycTotal==0 )
                ++ans;
        }
    }

    cout<<ans;

    return 0;

}
