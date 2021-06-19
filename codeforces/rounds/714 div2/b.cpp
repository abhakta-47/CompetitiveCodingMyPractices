#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll MOD=1000000007;

ll largestPower(ll n, ll p)
{
    ll x = 0;
 
    while (n) {
        n /= p;
        x += n;
    }
    return x;
}
 
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n! % p
ll modFact(ll n, ll p)
{
    if (n >= p)
        return 0;
 
    ll res = 1;
 
    // Use Sieve of Eratosthenes to find all primes
    // smaller than n
    bool isPrime[n + 1];
    memset(isPrime, 1, sizeof(isPrime));
    for (ll i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
 
    // Consider all primes found by Sieve
    for (ll i = 2; i <= n; i++) {
        if (isPrime[i]) {
            // Find the largest power of prime 'i' that divides n
            ll k = largestPower(n, i);
 
            // Multiply result with (i^k) % p
            res = (res * power(i, k, p)) % p;
        }
    }
    return res;
}

void sol(){
    ll n;
    cin>>n;
    ll a[n];
    ll i;
    bool allSame=true;
    for(i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);
    if(a[0]!=a[1]){
        cout<<0;
        return;
    }

    ll n0=2;
    for(i=2;i<n;i++){
        if(a[i]==a[0])
            ++n0;
        else
            break;
    }
    // cout<<"**";
    // return;  
    if(n0==n){
        cout<<modFact(n,MOD);
        return;
    }

    while(a[0]){
        if(a[0]%2){
            for(i=2;i<n;i++){
                if(a[i]%2==0){
                    cout<<0;
                    return;
                }
                a[i]/=2;
            }
        }
        else{
            for(i=2;i<n;i++){
                a[i]/=2;
            }
        }
        a[0]/=2;
    }

    cout<<((n0%MOD*(n0-1)%MOD)%MOD*modFact(n-2, MOD)%MOD)%MOD;    

    return;            
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i;
    cin>>t;
    while(t--){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
