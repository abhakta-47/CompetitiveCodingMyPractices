#include <bits/stdc++.h>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

int n;
int securitiesBuying(int z, int security_value[]) {
    int no_of_stocks = 0;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({security_value[i], i + 1});

    sort(v.begin(), v.end());
    int cur_buy = 0, cur_balance = z;
    for (int i = 0; i < n && cur_balance > 0; i++) {
        cur_buy = cur_balance / v[i].first;
        cur_buy = min(cur_buy, v[i].second);
        cur_balance -= (cur_buy * v[i].first);
        no_of_stocks += cur_buy;
        // cout << cur_balance << " " << no_of_stocks << "\n";
    }

    return no_of_stocks;
}

int main() {

    int z;
    cin >> z;
    vector<int> input_data;
    string buffer;
    int data;
    getline(cin, buffer);
    getline(cin, buffer);
    istringstream iss(buffer);

    while (iss >> data)
        input_data.push_back(data);

    n = input_data.size();

    int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }

    int no_of_stocks_purchased = securitiesBuying(z, security_value);
    cout << no_of_stocks_purchased;
}
