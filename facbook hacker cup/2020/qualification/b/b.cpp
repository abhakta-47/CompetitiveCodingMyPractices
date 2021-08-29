#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    string temp;
    ll na, nb;
    for (int i = 0; i < n; i++) {
        if (st.size() < 2) {
            st.push(s[i]);
            continue;
        }

        na = 0;
        nb = 0;

        temp = s[i];

        temp = st.top() + temp;
        st.pop();

        temp = st.top() + temp;
        st.pop();
        // cout << temp << " ";
        for (int j = 0; j < temp.size(); j++)
            if (temp[j] == 'A')
                ++na;
            else
                ++nb;

        if (na == 2 && nb == 1)
            st.push('A');
        else if (na == 1 && nb == 2)
            st.push('B');
        else
            for (int j = 0; j < temp.size(); j++)
                st.push(temp[j]);
    }

    if (st.size() == 1)
        cout << "Y";
    else
        cout << "N";
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
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
