#include<bits/stdc++.h>

using namespace std;
int ar[1005], dp[1005][1005], n, INF = 1e9;

void start(int i, int step, int cost) {
	if(i < 1 || i > n) return;
	if(cost + ar[i] > dp[i][step]) return;

	cost += ar[i];
	dp[i][step] = cost;
	start(i + step + 1, step + 1, cost);
	start(i - step, step, cost);
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> ar[i];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = INF;
	start(2, 1, 0);

	int ans = INF;
	for(int i = 0; i <= n; ++i) ans = min(ans, dp[n][i]);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
}
