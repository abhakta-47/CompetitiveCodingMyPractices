#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int factors[] = {1, 2, 4, 5, 10, 20, 25, 50, 100};

void sol()
{
    int k, i;
    cin >> k;
    for (i = 8; i >= 0; i--)
        if (k % factors[i] == 0)
            break;
    cout << 100 / factors[i];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
