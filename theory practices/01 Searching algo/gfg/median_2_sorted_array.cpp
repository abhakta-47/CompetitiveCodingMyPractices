//https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
// There are 2 sorted arrays A and B of size n each.
// Write an algorithm to find the median of the array
// obtained after merging the above 2 arrays(i.e. array of length 2n).
// The complexity should be O(log(n)).

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

inline int getMedian(int l, int r, int *a)
{
    if ((l + r) % 2)
        return (a[(l + r) / 2] + a[(l + r) / 2 + 1]) / 2;
    else
        return a[(l + r) / 2];
}

int findMedian(int l1, int r1, int *a1, int l2, int r2, int *a2)
{
    if (r1 - l1 == 1)
    {
        int a[4] = {a1[l1], a1[r1], a2[l2], a2[r2]};
        sort(a, a + 4);
        clog << a[1] << " " << a[2];
        return (a[1] + a[2]) / 2;
    }

    int median1 = getMedian(l1, r1, a1);
    int median2 = getMedian(l2, r2, a2);
    clog << l1 << "-" << r1 << " =" << median1 << "   "
         << l2 << "-" << r2 << " =" << median2 << "\n";
    if (median1 == median2)
        return median1;
    else if (median1 > median2)
        return findMedian(l1, (l1 + r1) / 2, a1, (l2 + r2) / 2 + 1, r2, a2);
    else
        return findMedian((l1 + r1) / 2 + 1, r1, a1, l2, (l2 + r2) / 2, a2);
}

void sol()
{
    int n;
    cin >> n;
    int a1[n], a2[n];
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < n; i++)
        cin >> a2[i];
    cout << findMedian(0, n - 1, a1, 0, n - 1, a2);
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
