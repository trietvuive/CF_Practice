#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 0, dp[5005][5005];
char a[5005], b[5005];
int main() {
	cin >> n >> m;
	scanf("%s%s", a + 1, b + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dp[i][j] = max(0, max(max(dp[i][j - 1] - 1, dp[i - 1][j] - 1), dp[i - 1][j - 1] + (a[i] == b[j]) * 4 - 2)),
			ans = max(ans, dp[i][j]);
	cout << ans << endl;
}
