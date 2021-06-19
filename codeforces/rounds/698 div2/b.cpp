#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
// float round(float var)
// {
//     // 37.66666 * 100 =3766.66
//     // 3766.66 + .5 =3767.16    for rounding off value
//     // then type cast to int so value is 3767
//     // then divided by 100 so the value converted into 37.67
//     float value = (int)(var * 100 + .5);
//     return (float)value / 100;
// }
int func()
{
    int n;
    int k, sum = 0, ans = 0, x = 0;
    double cf;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sum = arr[0];
    for (int i = 1; i < n; i++)
    {

        cf = (arr[i] *1.0/ (sum));
        cout << "sum-" << sum << " ai-" << arr[i] << " cf-" << setprecision(2) << cf << " " ;
        if (cf > (k / 100))
        {
            x = ceil(arr[i] * 100 / k - sum);
            cout << "x-" << x << " ";
            ans = ans + x;
            sum = sum + x;
            ////cout<<ans<<endl;
        }
        sum += arr[i];
    }
    //cout<<" ans ";
    cout << ans;

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
        ////cout<<"Case #"<<i+1<<": ";
        func();
        cout << "\n";
    }
}
