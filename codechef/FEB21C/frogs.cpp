// https://www.codechef.com/FEB21C/problems/FROGS
//done :)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

long long func()
{
    long long n, i;
    cin >> n;
    long long w[n], l[n];
    for (i = 0; i < n; i++)
        cin >> w[i];
    for (i = 0; i < n; i++)
        cin >> l[i];
    
    map<long long,pair<long long,long long>>m;// weight   pos     jump_cap

    for(i=0;i<n;i++)
        m.insert({w[i],{i,l[i]}});

    // for (auto im : m) 
    //     cout << im.first << "   " << im.second.first<<" "<<im.second.second
    //          << endl;
    long long last_pos=-1,cur_pos,cur_l,ans=0,cur_jump;
    // cout<<"lastP  wg  curP  curL    ifyes   cjump  newpos\n";
    for(auto im:m){
        cur_pos=im.second.first;cur_l=im.second.second;
        // cout<<last_pos<<"     "<<im.first<<"     "<<cur_pos<<"     "<<cur_l<<" ";
        if(cur_pos<=last_pos){
            cur_jump= ceil( (last_pos-cur_pos+1)*1.0/cur_l );
            ans += cur_jump;
            last_pos = cur_pos + cur_jump*cur_l;
            // cout<<"     ifyes   "<<cur_jump<<"     "<<last_pos<<"     "<<ans;
        }
        else
            last_pos=cur_pos;
        // cout<<"\n";
    }
    
    cout << ans;
    // cout<<"\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, i;
    t = 1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
