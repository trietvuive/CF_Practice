#include<bits/stdc++.h>

using namespace std;
int dp[11][11];
#define ll long long
int lcs(const string& power, const string& orig)
{
	int count = 0;
	for (int i = 0; i < orig.size(); ++i)
		if (count < power.size() && power[count] == orig[i])++count;
	return power.size() + orig.size() - count * 2;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int res = INT_MAX;
		for (ll i = 0; i < 64; ++i)
		{
			ll power = (ll)1 << i;
			res = min(res, lcs(to_string(power), s));
		}

		cout << res << endl;
	}
}
