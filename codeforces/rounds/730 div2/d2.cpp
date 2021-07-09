#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int n, k;

class KEquiv
{
public:
    ll value;
    vector<ll> kEquivArray;
    KEquiv() {}
    KEquiv(ll x, int c = 0)
    {

        value = x;
        setkEquiv();
        if (c)
            complement();
    }
    void complement()
    {
        for (ll i = 0; i < kEquivArray.size(); i++)
            kEquivArray[i] = k - kEquivArray[i];
        setValue();
    }
    void setValue()
    {
        value = 0;
        for (ll i = 0; i < kEquivArray.size(); i++)
            value += kEquivArray[i] * pow(k, i);
    }
    void setkEquiv()
    {
        ll x = value;
        kEquivArray.clear();
        while (x)
        {
            kEquivArray.push_back(x % k);
            x /= k;
        }
    }
    ll get(ll p) const
    {
        if (p >= kEquivArray.size())
            return 0;
        else
            return kEquivArray[p];
    }

    KEquiv operator^(const KEquiv &o1)
    {
        KEquiv tmp;
        cout << "\n";
        for (ll i = 0; i < max(o1.kEquivArray.size(), this->kEquivArray.size()); i++)
        {
            cout << o1.get(i) << "^" << this->get(i) << " = " << (o1.get(i) + this->get(i)) % k << "\t";
            tmp.kEquivArray.push_back((o1.get(i) + this->get(i)) % k);
        }
        tmp.setValue();
        return tmp;
    }
};

void sol()
{
    int x;
    cin >> n >> k;
    KEquiv N(n);
    cin >> x;
    KEquiv X(x);
    // cout << X.kEquivArray << " ";
    for (auto i : X.kEquivArray)
        cout << i;
    cout << "\n";
    int p;
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << X.value << " - ";
        if (i == 0)
            cout << 0;
        else
        {
            KEquiv tmp = (KEquiv(i) ^ KEquiv(i - 1, 1));
            cout << tmp.value;
            X = X ^ tmp;
        }
        cout << "\n";
        cout.flush();
        cin >> p;
        if (p == 1)
            return;
    }

    return;
}

int main()
{
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        //cout<<"Case #"<<i+1<<": ";
        sol();
        // cout << "\n";
    }
}
