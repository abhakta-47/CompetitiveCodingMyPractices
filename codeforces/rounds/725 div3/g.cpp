#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void sol()
{
    ll n1, n2, a, b;
    cin >> n1 >> n2 >> a >> b;

    vector<pair<ll, ll>> points;

    points.push_back({0, 0});

    // if (n1 % a == 0)
    points.push_back({n1 / a, 0});

    // if (n1 % b == 0)
    points.push_back({0, n1 / b});

    // if (n2 % b == 0)
    points.push_back({n2 / b, 0});

    // if (n2 % a == 0)
    points.push_back({0, n2 / a});

    if (a != b)
        points.push_back({(a * n1 - b * n2) / (a * a - b * b), (b * n1 - a * n2) / (b * b - a * a)});

    ll ans = 0;
    for (auto point : points)
    {
        if (0 <= (point.first + point.second) && (point.first + point.second)*(a+b) <= (n1 + n2) )
            ans = max(ans, point.first + point.second);
    }

    cout << ans;

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
