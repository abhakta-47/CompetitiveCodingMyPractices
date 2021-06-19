#include <bits/stdc++.h>

using namespace std;

// Basic Number Theory 2
// Check prime 
// Factorize


// create isPrime array upto N
void sieve(int N, bool *isPrime) {
    // bool isPrime[N+1];
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {                    //Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }
}

bool checkPrime(int N){
	bool *isPrime= new bool[N+1];
	sieve(N, isPrime);
	for(int i=0;i<=N;i++)
		if(isPrime[i])
			cout << i <<" - "<<isPrime[i]<<"\n";
	return isPrime[N];
}


// factorizatio O(sqrt(n))
vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int main(){
	checkPrime(100);
	// cout << "nothing here";
}