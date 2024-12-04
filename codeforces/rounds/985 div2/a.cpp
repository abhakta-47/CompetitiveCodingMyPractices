#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

bool get_r(ll f, ll r, ll e){
  clog<<"*"<<f<<"."<<r<<"."<<e<<"=";
  f -= e;
  if(r==0) return (f==0);
  clog<<f%r<<"."<<f/r<<"; ";
  return ( f%r==0 && f/r>=0);
}

void sol() {
  ll n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  ll px=0, py=0;
  loop(i, 0, s.length()) {
    if(s[i]=='N') py++;
    if(s[i]=='S') py--;
    if(s[i]=='E') px++;
    if(s[i]=='W') px--;
  }
  clog<<px<<"."<<py<<"; ";
  if(px==a && py==b){
    cout<<"YES";
    return;
  }
  ll x=0,y=0;
  loop(i, 0, s.length()) {
    if(s[i]=='N') y++;
    if(s[i]=='S') y--;
    if(s[i]=='E') x++;
    if(s[i]=='W') x--;
    clog<<a<<"."<<px<<"."<<x<<" "<<b<<"."<<py<<"."<<y<<"; ";
    // a = px*n + x
    if(get_r(a,px,x) && get_r(b, py,y)){
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
    clog << "Case #" << i + 1 << ": \n";
    sol();
    clog<<"\n";
    cout << "\n";
  }
}
