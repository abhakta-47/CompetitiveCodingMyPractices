#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

// attrHappy enddate id

ll ans, curAns;
ll d, n, k;
class curAttr {
  public:
    set<ll> attrId;
    // happy enddate id
    set<pair<ll, pair<ll, ll>>> happiness;
    void insert(pair<ll, pair<ll, ll>> attr) {
        // cout << "add" << attr.first << ": ";
        happiness.insert(attr);
        attrId.insert(attr.second.second);
        curAns += attr.first;
        // cout << " +" << curAns << ": ";
        if (attrId.size() > k)
            this->remove();
        // cout << ":c " << curAns << ": ";
        ans = max(curAns, ans);
        // this->display();
    }
    void remove() {
        // cout << "autoremove ";
        auto ih = happiness.begin();
        curAns -= ih->first;
        // ans = max(curAns, ans);
        attrId.erase(ih->second.second);
        happiness.erase(ih);
    }
    void remove(pair<ll, pair<ll, ll>> attr) {
        // cout << "remove" << attr.second.second << ": ";
        // ans = max(curAns, ans);
        auto itr = attrId.find(attr.second.second);
        if (itr == attrId.end())
            return;
        curAns -= attr.first;
        // cout << " -" << attr.first << ": ";
        // cout << ":c " << curAns << ": ";
        happiness.erase(attr);
        attrId.erase(itr);
        // this->display();
    }
    void display() {
        cout << "ids ";
        for (auto it : attrId)
            cout << it << ", ";
        cout << " :: ";
        for (auto it : happiness)
            cout << it.second.first << " " << it.second.second << ", ";
        cout << "\n";
    }
};

void sol() {
    ans = 0;
    curAns = 0;
    cin >> d >> n >> k;
    ll dp[d + 2] = {0};
    map<ll, pair<ll, ll>> starts[d + 1];
    map<ll, pair<ll, ll>> ends[d + 1];
    ll h, s, e;
    for (ll i = 0; i < n; i++) {
        cin >> h >> s >> e;
        starts[s][h] = {e + 1, i};
        ends[e + 1][h] = {e + 1, i};
    }
    // attrId attrHappy
    curAttr curAttr;
    for (ll i = 1; i <= d; i++) {
        // cout << i << ": ";
        for (auto im : ends[i]) {
            curAttr.remove(im);
        }
        for (auto im : starts[i]) {
            curAttr.insert(im);
        }
    }
    // curAttr.insert({1, 10});
    // curAttr.insert({2, 13});
    // curAttr.remove({3, 15});
    cout << ans;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        // cout << "\n";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
