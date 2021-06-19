#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

bool findPartiion(int arr[], int n, int x)
{
    int sum = 0;
    int i, j;

    for (i = 0; i < n; i++)
        if (x != i)
            sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool part[sum / 2 + 1];

    for (i = 0; i <= sum / 2; i++)
        part[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (x == i)
            continue;
        for (j = sum / 2; j >= arr[i]; j--)
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
    }

    return part[sum / 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    if (!findPartiion(a, n, -1))
    {
        cout << 0;
        return 0;
    }
    for (i = 0; i < n; i++)
        if (!findPartiion(a, n, i))
        {
            cout << 1 << "\n"
                 << i + 1;
            return 0;
        }
}
