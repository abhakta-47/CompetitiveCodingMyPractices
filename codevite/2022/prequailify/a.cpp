#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

vector<ll> nums;
vector<ll> primes;
ll limitp = 1e10;

void parseInput(const string &input) {
    string word = "";
    ll n = input.length();
    for (ll i = 0; i < n; i++)
        if (input[i] == ' ') {
            nums.push_back(stoi(word));
            word = "";
        } else
            word = word + input[i];
    nums.push_back(stoi(word));
}

inline ll __lcm(ll &x, ll &y) { return (x * y) / __gcd(x, y); }

void sol() {
    string input;
    getline(cin, input);
    // cout << input << ": ";
    parseInput(input);
    sort(nums.begin(), nums.end());
    ll q = nums[0];
    nums.erase(nums.begin());
    // for (auto num : nums)
    //     cout << num << ", ";
    ll lcm = nums[0];
    for (auto num : nums) {
        // cout << num;
        lcm = __lcm(lcm, num);
    }
    // cout << q << " " << lcm;

    if (__lcm(lcm, q) != 1)
        cout << "None";

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        // clog << "Case #" << i + 1 << ": \n";
        sol();
        // clog<<"\n";
        // cout << "\n";
    }
}
