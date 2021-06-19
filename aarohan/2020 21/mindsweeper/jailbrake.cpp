#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long

ll n=(ll)677475558566471808;
// ll n=(ll)100;

void SieveOfEratosthenes()
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool *prime=new bool(n + 1);
    // bool prime[n+1];
    memset(prime, true, n+1);
 
    for (ll p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    ll nPrimes=0;
    // Print all prime numbers
    for (ll p = 2; p <= n; p++)
        if (prime[p]){
            // cout<<p<<", ";
            ++nPrimes;
        }
    cout<<"\n"<<nPrimes;
}


int func(){
    cout<<n<<"\n";
    SieveOfEratosthenes();
    // cout<<fixed;
    // cout<<n<<" "<<log(n)<<"  "<< (n/(log(n)-1));
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    // cin>>t;
    t=1;
    for(i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout<<"\n";
    }
}
