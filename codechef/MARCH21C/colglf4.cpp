#include <bits/stdc++.h>

using namespace std;

unsigned long long n,e,h,a,b,c,z;
// n - no friends
// e - no egss
// h - bar
// a - price omlette
// b - price shake
// c - price cake

class Point{
public:
    unsigned long long x,y,z;
    Point(){
        x=0; y=0; z=0;
    }
    Point(unsigned long long x, unsigned long long y, unsigned long long z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    void set(unsigned long long x, unsigned long long y, unsigned long long z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    unsigned long long getPrice(){
        // cout<<x<<" "
        //     <<y<<" "
        //     <<z<<" "
        //     <<a*x+b*y+c*z<<" getPrice\n";
        return ( a*x + b*y + c*z );
    }
    bool isValid(){
    // cout<<x<<" "
    //     <<y<<" "
    //     <<z<<" isValid\n";
    
    // constraints 5 egg, bar, x+y+z=n, x>=0, y>=0

        if( 0<=x && 0<=y && 0<=z )  // 0<=
            if( 2*x+z<=e && 3*y+z<=h ) // egg bar
                if(x+y+z==n) // =n
                    return true;
        
        return false;
    }
};

int func(){
    cin>>n>>e>>h>>a>>b>>c;
    // cout<<"\nn"
    //     <<n<<" e"
    //     <<e<<" h"
    //     <<h<<" a"
    //     <<a<<" b"
    //     <<b<<" c"
    //     <<c<<"\n";
    
    bool flag=false;
    for(unsigned long long z=0; z<=min(n , min(e,h)); z++)
        if( ((e-z)/2 + (h-z)/3 + z) >= n ){
            flag=true;
            break;
        }
    
    if(!flag){
        cout<<"-1";
        return 0;
    }
    
    unsigned long long minPrice;
    bool first=true;
    for(unsigned long long z=0; z<=min( n, min(e,h)); z++){
        
        unsigned long long ymax=(h-z)/3;
        unsigned long long xmin=( n-z>=ymax ? n-z-ymax : 0);
        unsigned long long xmax=(e-z)/2;
        unsigned long long ymin=( n-z>=xmax ? n-z-xmax : 0);
        
        Point points[4];
        points[0].set( xmin, ymax, z);
        points[1].set( xmax, ymin, z);
        points[2].set( n-z, 0, z);
        points[3].set( 0, n-z, z);
        for(int i=0;i<4;i++)
            if( points[i].isValid() ){
                if(first){
                    minPrice=points[i].getPrice();
                    first=false;
                }
                else
                    minPrice=min(minPrice, points[i].getPrice());
            }
    }

    cout<<minPrice;
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    //t=1;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
