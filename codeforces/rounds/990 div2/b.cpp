#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    string s;
    cin>>s;
    // cout<<s<<"\t\t";
    unordered_map<char, ll> freq;
    loop(i, 0, n) {
        freq[s[i]]++;
    }
    ll max_freq=freq[s[0]], min_freq=freq[s[0]];
    for(auto ia : freq){
        max_freq = max(max_freq, ia.second);
        min_freq = min(min_freq, ia.second);
    }
    char max_str, min_str;
    for(auto ia : freq){
        if(ia.second == max_freq) {
            max_str = ia.first;
        }
        if(ia.second == min_freq) {
            min_str = ia.first;
        }
    }
    if(max_freq==min_freq && freq.size()!=1){
        max_str = freq.begin()->first;
    }
    // cout<<max_str<<" "<<min_str<<" ";
    loop(i, 0, n) {
        if(s[i] == min_str) {
            s[i] = max_str;
            break;
        }
    }
    cout<< s;

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
