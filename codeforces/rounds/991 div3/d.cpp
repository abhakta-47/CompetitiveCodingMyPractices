#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    string s;
    cin>>s;
    ll n = s.length();
    list<char>chars;
    loop(i,0,n) chars.push_back(s[i]);

    ll delta = 0;
    char maxx;
    auto delta_pos = chars.begin();
    while(chars.size()){
        delta=0;
        maxx = chars.front();
        delta_pos = chars.begin();
        for(auto ic=chars.begin(); ic!=chars.end() && delta<=9; ++ic, ++delta){
            char x = char(*ic - delta);
            if( '0'<=x && x<='9' )
                if( x>maxx ){
                    maxx = x;
                    delta_pos = ic;
                }
        }
        cout << maxx;
        chars.erase(delta_pos);
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
