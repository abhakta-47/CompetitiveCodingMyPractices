#include<bits/stdc++.h>

using namespace std;
#define ll long long

void find_max_sum(multiset<ll>&widths, ll box_width){
    if(widths.empty())
        return;

    ll sum=0;

    auto width=widths.upper_bound(box_width-sum);
    if(width!=widths.begin())
        --width;
    if(*width+sum>box_width)
            return;

    //cout <<box_width<<"-"<<*(width)<<", ";
    sum+= *(width);
    widths.erase(width);

    while(!widths.empty()){
        //cout <<box_width-sum<<"-";
        
        width=widths.upper_bound(box_width-sum);
        if(width!=widths.begin())
            --width;

        if(*width+sum>box_width)
            break;
        
        //cout <<*width<<", ";
        sum += *width;
        widths.erase(width);
    }
    //cout <<"\n";
}


int func(){
    ll n, box_width;
    cin>>n>>box_width;
    ll i, x;
    multiset<ll>widths;
    for(i=0;i<n;i++){
        cin>>x;
        widths.insert(x);
    }

    ll ans=0;
    while(!widths.empty()){
        // //cout <<ans<<"-> ";
        find_max_sum(widths, box_width);
        ++ans;
    }
    cout <<ans;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        ////cout <<"Case #"<<i+1<<": ";
        func();
        cout <<"\n";
    }
}
