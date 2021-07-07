#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int depth(vector<int> *v, int curNode, int level)
{
    if (v[curNode].size() == 0)
        return level;
    int curLevel = level;
    for (auto iv : v[curNode])
    {
        curLevel = max(curLevel, depth(v, iv, level + 1));
    }
    return curLevel;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n;
    vector<int> v[n];
    int root;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == -1)
            root = i;
        else
            v[x].push_back(i);
    }
    cout << depth(v, root, 1) << "\n";
}
