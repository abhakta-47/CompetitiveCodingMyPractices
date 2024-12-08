#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

class Logger {
    public:
    bool enabled;
    Logger(bool enabled=true){
        this->enabled = enabled;
    }
    ostream operator<<(string s){
        if(enabled) cout << s;
        return cout;
    }
};

Logger logger;

void sol() {
    ll n;
    cin >> n;
    logger<<"n="<<n<<"\n";

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
        clog << "Case #" << i + 1 << ": \n";
        sol();
        clog<<"\n";
        cout << "\n";
    }
}
