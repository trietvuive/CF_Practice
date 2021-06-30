/*
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, MAX = 200011;
int dp[MAX];
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < 10; i++)dp[i] = 1;
	for (int i = 10; i < MAX; i++)dp[i] = (dp[i - 10] + dp[i - 9]) % MOD;
	while (t--)
	{
		int n, m, ans = 0;		
		scanf("%d%d", &n, &m);
		while (n > 0)
		{
			ans = (ans + dp[n % 10 + m]) % MOD;
			n /= 10;
		}
		cout << ans << endl;
	}
}
*/