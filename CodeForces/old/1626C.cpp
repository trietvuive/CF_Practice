#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k[102], h[102]; 
ll dp[102];
int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		ll n; cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> k[i];
		for (int i = 1; i <= n; ++i)
			cin >> h[i];
		dp[0] = 0;

		for (int i = 1; i <= n; ++i)
		{
			int now = 0;
			dp[i] = 1e18;
			for (int j = i; j; --j)
			{
				now = max(now, h[j] + k[i] - k[j]);
				if (k[i] - now >= k[j - 1])
					dp[i] = min(dp[i], dp[j - 1] + 1ll * now * (now + 1) / 2);
			}
		}
		cout << dp[n] << endl;
	}
}