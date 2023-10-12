#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

int dfs(int node, vector<int> &dp, const graph& g) {
	if(dp[node] != -1) return dp[node];

	int mx = 0;
	for(int child : g[node])
		mx = max(mx, dfs(child, dp, g));

	return dp[node] = mx+1;
}

void solve() {
	int n, m, x, y; cin >> n >> m;
	graph g(n+1);
	vector<int> dp(n+1, -1);
	for(int i = 0; i < m; ++i) 
		cin >> x >> y, g[x].push_back(y);

	int mx = 0;
	for(int i = 1; i <= n; ++i)
		mx = max(mx, dfs(i, dp, g));

	cout << mx-1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

