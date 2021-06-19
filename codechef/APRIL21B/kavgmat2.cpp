#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll k;

class Matrix
{
public:
    ll **a, **sum;
    ll n, m;

    void allocMatrix(){
        a=new ll *[n];
        for (ll i = 0; i < n; i++)
            a[i] = new ll[m];
        sum=new ll *[n];
        for(ll i=0;i<n;i++)
            sum[i]=new ll[m];
    }
    void deallocMatrix(){
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
    }
    
    Matrix(int row, int collumn){
        n = row;
        m = collumn;
        allocMatrix();
    }
    ~Matrix(){
        deallocMatrix();
    }

    void readMatrix(){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                a[i][j]-=k;
            }
        pre_sum_matrix();
    }
    void displayMatrix(){
        cout << "Displaying matrix content :: \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << "   " << a[i][j];
            cout << "\n";
        }
        cout << "\n";
    }
    void displaySumMatrix(){
        cout << "Displaying Sum matrix content :: \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << "   " << sum[i][j];
            cout << "\n";
        }
        cout << "\n";
    }
    ll getValue(pair<ll,ll>p){
        return a[p.first][p.second];
    }

    void pre_sum_matrix(){
        ll i,j;
        for(i=0;i<n;i++){
            sum[i][0]=a[i][0];
            for(j=1;j<m;j++)
                sum[i][j]=a[i][j]+sum[i][j-1];
        }

        for(j=0;j<m;j++)
            for(i=1;i<n;i++)
                sum[i][j]+=sum[i-1][j];
    }

    bool avg_matrix(ll x,ll y,ll l){
        ll actualSum;
        if(x==0 && y==0)
            actualSum= sum[x+l-1][y+l-1];
        else if(x==0)
            actualSum= sum[x+l-1][y+l-1]
                        -sum[x+l-1][y-1];
        else if(y==0)
            actualSum= sum[x+l-1][y+l-1]
                        -sum[x-1][y+l-1];
        else
            actualSum= sum[x+l-1][y+l-1]
                        -sum[x+l-1][y-1]
                        -sum[x-1][y+l-1]
                        +sum[x-1][y-1];
        // cout<<actualSum<<","<<actualSum<<","<<l*l;
        return ( actualSum>=0 ? true : false );
    }
    bool avg_matrix(pair<ll,ll>p1,pair<ll,ll>p2){
        ll actualSum;
        ll x =p1.first, y =p1.second;
        ll x1=p2.first, y1=p2.second; 
        if(x==0 && y==0)
            actualSum= sum[x1][y1];
        else if(x==0)
            actualSum= sum[x1][y1]
                        -sum[x1][y-1];
        else if(y==0)
            actualSum= sum[x1][y1]
                        -sum[x-1][y1];
        else
            actualSum= sum[x1][y1]
                        -sum[x1][y-1]
                        -sum[x-1][y1]
                        +sum[x-1][y-1];
        // cout<<actualSum<<","<<actualSum<<","<<l*l;
        return ( actualSum>=0 ? true : false );
    }

    ll innerCounter(ll x, ll y){
        // cout<<x<<","<<y<<"->\n";
        vector<pair<ll,ll>>v;
        while(x<n&&y<m){
            v.push_back({x,y});
            ++x;++y;
        }
        ll ans=0,p=v.size();
        for(ll i=v.size()-1; i>=0; i--){
            if( getValue(v[i])>=0){
                ans+=(ans+1);
                p=i;
                continue;
            }
            // v[i]<0
            for(ll j=p;j<v.size();j++)
                if(avg_matrix(v[i],v[j])){
                    ans+=v.size()-j;
                    break;
                }
        }
        // cout<<ans<<"\n";
        return ans;
    }
    ll counter(){
        ll ans=0;
        for(ll j=0;j<m;j++)
            ans+=innerCounter(0,j);
        for(ll i=1;i<n;i++)
            ans+=innerCounter(i,0);
        return ans;
    }
};

void sol(){

    ll n,m;
    cin>>n>>m>>k;
    ll i,j;
    Matrix a(n,m);
    a.readMatrix();
    // a.displayMatrix();
    // a.displaySumMatrix();
    // return;
    
    // ll ans=0;
    // for(ll l=1;l<=min(n,m);l++){
    //     // cout<<l<<"->\n";
    //     ll jRange=m-l+1;
    //     for(i=0; i+l-1<n; i++){
    //         // cout<<i<<"- ";
    //         for(j=0; j<jRange; j++){
    //             // cout<<j<<". ";
    //             if( a.avg_matrix(i,j,l)){
    //                 // cout<<i<<","
    //                 //     <<j<<" "
    //                 //     <<(n-l-i+1)<<"*"<<(jRange-l-j+1)<<" "
    //                 //     <<(n-l-i+1)*(jRange-l-j+1)<<"\n";
    //                 ans+=(n-l-i+1)*(jRange-l-j+1);
    //                 jRange=j+1;
    //                 break;
    //             }
    //             // cout<<" ";
    //         }
    //         // cout<<"\n";
    //     }
    // }
    // cout<<ans;
    cout<<a.counter();
    return;            
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout<<"\n";
    }
}
