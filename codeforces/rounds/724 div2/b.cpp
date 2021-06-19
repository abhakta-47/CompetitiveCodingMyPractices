#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

string is_present(string &s, set<string> &st, ll len, string &ans)
{
    if (ans.size() == len)
    {
        if (st.count(ans))
            return "";
        return ans;
    }
    string sol = "";
    for (int i = 0; i < 26; i++)
    {
        ans.push_back(i + 'a');
        sol = is_present(s, st, len, ans);
        ans.pop_back();
        if (sol != "")
            break;
    }
    return sol;
}

void sol()
{
    ll n;
    cin >> n;
    set<string> st;
    string s;
    cin >> s;
    int i;
    for (i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            st.insert(s.substr(i, j - i + 1));
        }
    }
    string ans = "";
    for (i = 1; i < n + 2; i++)
    {
        string temp = "";
        ans = is_present(s, st, i, temp);
        if (ans != "")
            break;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        cout << "\n";
    }
}
