#include <bits/stdc++.h>

using namespace std;

int func(){
	unsigned long long p,a,b,c;
	cin >> p >> a >>b >>c;

	a = ( p%a ? a - p%a : 0 );
	b = ( p%b ? b - p%b : 0 );
	c = ( p%c ? c - p%c : 0 );

	cout << min(a, min(b,c) );

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
