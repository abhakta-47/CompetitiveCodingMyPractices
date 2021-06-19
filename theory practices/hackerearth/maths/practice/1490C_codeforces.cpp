#include <bits/stdc++.h>

using namespace std;

int func(){
    double x;
    cin >> x;
    double  cbrtX=cbrt(x);
    // cout  << x << " " << cbrtX << "\n";
    for(double a=1; a<(cbrtX); a++){
        double b = x - a*a*a;
        b=cbrt(b);
        // cout << a << " "
        //      << b << " "
        //      << floor(b) << " "
        //      <<(b==floor(b)) <<"\n";
        if(b==floor(b)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
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
