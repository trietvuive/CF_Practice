#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, dp[6][N];
string S, perm[6] = { "abc","acb","bac","bca","cab","cba" };
int main()
{
	cin >> n >> m >> S;
	for (int t = 0; t < 6; ++t)
		for (int i = 1; i <= n; ++i) dp[t][i] = dp[t][i - 1] + (S[i - 1] != perm[t][(i - 1) % 3]);
	for (int i = 0; i < m; ++i)
	{
		int l, r, ans = N;
		cin >> l >> r;
		for (int t = 0; t < 6; ++t)
			ans = min(ans, dp[t][r] - dp[t][l - 1]);
		cout << ans << endl;
	}
}
