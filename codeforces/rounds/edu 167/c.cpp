#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

void sol() {
    ll n;
    cin >> n;
    vector<ll> ratings1(n), ratings2(n);
    loop(i, 0, n) cin >> ratings1[i];
    loop(i, 0, n) cin >> ratings2[i];
    ll final_rating1 = 0, final_rating2 = 0;
    loop(i, 0, n) {
        if (ratings1[i] == ratings2[i])
            continue;

        if (ratings1[i] > ratings2[i]) {
            final_rating1 += ratings1[i];
        } else if (ratings1[i] < ratings2[i]) {
            final_rating2 += ratings2[i];
        }
    }
    clog << "f1 f2: " << final_rating1 << " " << final_rating2 << ":: ";
    ll pos_delta = 0, neg_delta = 0;
    loop(i, 0, n) {
        if (ratings1[i] != ratings2[i])
            continue;
        if (ratings1[i] == 1)
            pos_delta += ratings1[i];
        if (ratings1[i] == -1)
            neg_delta += ratings1[i];
    }

    clog << "pd nd: " << pos_delta << " " << neg_delta << ":: ";
    ll max_rating = max(final_rating1, final_rating2);
    ll min_rating = min(final_rating1, final_rating2);
    clog << "maxr minr: " << max_rating << " " << min_rating << ":: ";

    ll new_max_rating = max_rating + neg_delta;
    ll new_min_rating = min_rating + pos_delta;
    clog << "nmr nmr: " << new_max_rating << " " << new_min_rating << ":: ";

    if (new_min_rating <= new_max_rating) {
        cout << new_min_rating;
        return;
    }

    ll diff = new_min_rating - new_max_rating;
    cout << new_max_rating + diff / 2;

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
        clog << "\nCase #" << i + 1 << ": \n";
        sol();
        cout << "\n";
    }
}