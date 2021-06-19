#include<bits/stdc++.h>

using namespace std;

#define ll long long

int ct1=1,ct2=2,n;

void printFormat(int b, int x){
    cout<<b<<" "
        // <<x<<", "
        <<( x%n ? x/n+1 : x/n)<<" "
        <<( x%n ? x%n : n )<<"\n";
    cout.flush();
}

void print(int a){

    if( ct2>n*n ){
        // cout<<"*";
        if(a==3)
            printFormat(1,ct1);
        else
            printFormat(3,ct1);

        if( n%2==0 && ct1%n==(n-1))
            ct1+=3;
        else
            ct1+=2;

        return;
    }

    if( ct1>n*n ){
        // cout<<"|";
        if(a==3)
            printFormat(2,ct2);
        else
            printFormat(3,ct2);

        if( n%2==0 && ct2%n==0)
            ++ct2;
        else
            ct2+=2;

        return;
    }



    if(a==1){
        // cout<<ct2<<"    ";
        printFormat(2,ct2);
        if( n%2==0 && ct2%n==0){
            // cout<<".";
            ++ct2;
        }
        else
            ct2+=2;
        // cout<<ct2<<"\n";
    }
    else{
        // cout<<ct1<<"    ";
        printFormat(1,ct1);
        if( n%2==0 && ct1%n==(n-1)){
            // cout<<".";
            ct1+=3;
        }
        else
            ct1+=2;
        // cout<<ct1<<"\n";
    }
    
}

int main(){
    ct1=1;ct2=2;
    int a;
    cin>>n;

    for(int i=0;i<n*n;i++){
        cin>>a;
        print(a);
    }

    return 0;
}
