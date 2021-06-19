#include<bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll>primes;
bool prime[1000000 + 1];
void SieveOfEratosthenes(ll n){

    
    memset(prime, true, sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
            // cout << p << " ";
}



int func(){

    SieveOfEratosthenes(1000000);
    cout<<primes.size()<<"\n";
    ll ans=(ll)0;
    // set<ll>sums;
    // for(int i=0;i<primes.size();i++){
    //     cout<<i<<"-> \n";
    //     for(int j=i+1; j<primes.size(); ++j){
    //         // cout<<"    "<<j<<"\n";
    //         if( 2<=primes[i]+primes[j] && primes[i]+primes[j]<=1000000)
    //             sums.insert(primes[i]+primes[j]);
    //         else
    //             break;           
    //     }
    //     // cout<<ans<<"\n";
    // }
    // // cout<<ans;
    // cout<<sums.size();

    for(int i=2;i<=1000000;i++){
        cout<<i<<"-> ";
        for(int j=0; j<primes.size(); j++){
            if(primes[j]>=i)
                break;
            if( prime[i-primes[j]] ){
                cout<<primes[j]<<" "<<i-primes[j];//<<"\n";
                ++ans;
                break;
            }
        }
        cout<<"\n";
    }

    cout<<ans;

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
