#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    ll x = 0, y = 0;
    loop(i, 0, n) {
        if (s[i] == 'N')
            y++;
        if (s[i] == 'S')
            y--;
        if (s[i] == 'E')
            x++;
        if (s[i] == 'W')
            x--;
    }


    ll delta_x, delta_y;
    delta_x = delta_y = 0;
    loop(i, 1, n+1) {
        // repeat*N + delta = {a,b}
        if(i>0){
            if (s[i-1] == 'N')
                delta_y++;
            if (s[i-1] == 'S')
                delta_y--;
            if (s[i-1] == 'E')
                delta_x++;
            if (s[i-1] == 'W')
                delta_x--;
        }

        if(x==0 && y==0){
            if(a==delta_x && b==delta_y){
                cout<<"YES";
                return;
            }
            continue;
        }
        if(x==0){
            if(a!=delta_x) continue;
            if(((b-delta_y)%y==0)){
                cout<<"YES";
                return;
            }
            continue;
        }
        if(y==0){
            if(b!=delta_y) continue;
            if(((a-delta_x)%x==0)){
                cout<<"YES";
                return;
            }
        }
        
        if(((a-delta_x)%x==0) && ((b-delta_y)%y==0) && (((a-delta_x)/x)==((b-delta_y)/y))){
            cout<<"YES";
            return;
        }
    }

    cout << "NO";
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
