#include <bits/stdc++.h>

using namespace std;

void sol()
{
	long long n;
	string s;
	cin >> n >> s;
	// cout << n << s << "\n";
	vector<long long> vs, vd;
	long long i, prev = 0;
	for (i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
			continue;
		// cout << i << s[i - 1] << s[i] << "->";
		if (s[i] == '.')
			vs.push_back(i - prev);
		else
			vd.push_back(i - prev);
		prev = i;
	}
	if (s[i - 1] != '.')
		vs.push_back(i - prev);
	else
		vd.push_back(i - prev);

	long long totalS = 0;
	for (i = 1; i < vs.size(); i++)
	{
		// totalS += vs[i];
		vs[i] += vs[i - 1];
	}
	if (!vs.empty())
		totalS = vs[vs.size() - 1];
	long long ans = 0;

	if (s[0] == '.' && !vd.empty())
		vd.erase(vd.begin());
	if (s[n - 1] == '.' && !vd.empty())
		vd.erase(--vd.end());

	for (i = 0; i < vd.size(); i++)
	{
		// cout << i;
		ans += vd[i] * min(vs[i], totalS - vs[i]);
	}

	cout << ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		sol();
		cout << "\n";
	}
}
