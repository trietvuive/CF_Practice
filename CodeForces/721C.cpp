#include<bits/stdc++.h>
using namespace std;

int n, m, T, u[5005], v[5005], t[5005], dp[5005][5005], trace[5005][5005], ans;

void print(int length, int node) {
	if (length == 0) return;
	if (trace[length][node])
		print(length - 1, trace[length][node]);
	cout << node << ' ';
}
int main() {
	cin >> n >> m >> T;
	for (int i = 0; i < m; ++i)
		cin >> u[i] >> v[i] >> t[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) dp[i][j] = T + 1;

	dp[1][1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j) 
			if (dp[i - 1][u[j]] + t[j] < dp[i][v[j]])
				dp[i][v[j]] = dp[i - 1][u[j]] + t[j],
				trace[i][v[j]] = u[j];
		if (dp[i][n] <= T) ans = i;
	}
	cout << ans << endl;
	print(ans, n);
}