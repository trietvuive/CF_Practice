#include<bits/stdc++.h>
const int MOD = 1000000007;
#define ll long long
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		ll ans = 2;
		if (k == 1)
		{
			printf("1\n");
			continue;
		}
		if (n == 1)
		{
			printf("2\n");
			continue;
		}
		vector<vector<ll>> dp(k, vector<ll>(n-1, 0));
		for (int i = 0; i < n - 1; i++)
			dp[1][i] = 1;
		ans += n - 1;
		bool backward = true;
		for (int strength = 2; strength < k; strength++)
		{
			if (backward)
			{
				dp[strength][n - 2] = dp[strength - 1][n - 2];
				ans = (ans + dp[strength][n - 2]) % MOD;
				for (int layer = n - 3; layer >= 0; layer--)
					dp[strength][layer] = (dp[strength][layer + 1] + dp[strength - 1][layer]) % MOD, ans = (ans + dp[strength][layer]) % MOD;
			}
			else
			{
				dp[strength][0] = dp[strength - 1][0];
				ans = (ans + dp[strength][0]) % MOD;
				for (int layer = 1; layer < n - 1; layer++)
					dp[strength][layer] = (dp[strength][layer - 1] + dp[strength - 1][layer]) % MOD, ans = (ans + dp[strength][layer]) % MOD;
			}
			backward = !backward;
		}
		printf("%d", ans);
		printf("\n");
	}
}
