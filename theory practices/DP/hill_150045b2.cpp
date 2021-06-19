//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hill-150045b2/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

void sol(){
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
        cin>>a[i];
    int dp_left[n],dp_right[n];
    dp_left[0]=0;
    for(i=1;i<n;i++){
        if( a[i-1]>a[i] )
            dp_left[i]=dp_left[i-1]+1;
        else
            dp_left[i]=0;
    }

    dp_right[n-1]=0;
    for(i=n-2;i>=0;i--){
        if( a[i]<a[i+1] )
            dp_right[i]=dp_right[i+1]+1;
        else
            dp_right[i]=0;
    }

    for(i=0;i<n;i++)
        cout<<dp_left[i]+dp_right[i]+1<<" ";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

	int t;
    cin >> t;
    while(t--){
        sol();
        cout<<"\n";
    }
}