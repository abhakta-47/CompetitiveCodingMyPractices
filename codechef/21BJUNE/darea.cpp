// https://www.codechef.com/JUNE21B/problems/DAREA

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

ll solUtil(map<ll, set<ll>> &m)
{
    map<ll, ll> area_front, area_back;
    vector<ll> poss;

    ll min_x = *(m.begin()->second.begin()),
       max_x = *--(m.begin()->second.end());

    for (auto im : m)
    {
        min_x = min(min_x, *im.second.begin());
        max_x = max(max_x, *--im.second.end());

        area_front[im.first] = (im.first - m.begin()->first) * (max_x - min_x);
        poss.pb(im.first);
    }

    min_x = *((--m.end())->second.begin());
    max_x = *--((--m.end())->second.end());
    for (auto im = m.rbegin(); im != m.rend(); im++)
    {
        min_x = min(min_x, *im->second.begin());
        max_x = max(max_x, *(--im->second.end()));

        area_back[im->first] = (m.rbegin()->first - im->first) * (max_x - min_x);
    }

    // for (auto im : area_front)
    //     clog << im.first << " " << im.second << "\n";
    // clog << "\n";
    // for (auto im : area_back)
    //     clog << im.first << " " << im.second << "\n";
    // clog << "\n";

    // for (int i = 0; i < poss.size() - 1; i++)
    // clog<<im[poss]

    ll ans_area = area_front.rbegin()->second;
    ll cur_area;
    for (int i = 0; i < poss.size() - 1; i++)
    {
        cur_area = area_front[poss[i]] + area_back[poss[i + 1]];
        ans_area = min(cur_area, ans_area);
    }
    return ans_area;
    // clog << ans_area << " ";
}

void sol()
{

    int n;
    cin >> n;
    ll x, y;

    map<ll, set<ll>> mv, mh;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        mh[x].insert(y);
        mv[y].insert(x);
    }

    cout << min(solUtil(mh), solUtil(mv));

    return;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // clog.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        // clog << "Case : \n";
        sol();
        cout << "\n";
        // clog << "\n";
    }
}
