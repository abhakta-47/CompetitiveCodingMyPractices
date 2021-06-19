#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int N = 1e2 + 5;
int pre_value[N];
int ans[N];

void sol()
{
    int k;
    cin >> k;
    cout << ans[4 * k + 1];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < N; i++)
    {
        pre_value[i] = i;
        ans[i] = 0;
    }

    for (int val = 2; val < N; val++)
    {
        if (pre_value[val] == val)
        {
            pre_value[val] = val - 1;
            for (int idx = 2 * val; idx < N; idx += val)
                pre_value[idx] = (pre_value[idx] / val) * (val - 1);
        }
    }

    // for (int i = 0; i < N; i++)
    // clog << i << "=" << pre_value[i] << ", ";

    for (int idx = 1; idx < N; idx++)
    {
        ans[idx] += idx - 1;
        clog << idx << "->";
        for (int j = 2 * idx; j < N; j += idx)
        {
            if (j == 45)
                clog << j << " +="
                     << idx << "*(" << 1 << "+" << pre_value[j / idx] << "[" << j / idx << "] )/" << 2
                     << " =" << idx * ((1 + pre_value[j / idx]) / 2) << ", ";
            ans[j] += idx * ((1 + pre_value[j / idx]) / 2);
        }
        clog << "\n";
    }

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
