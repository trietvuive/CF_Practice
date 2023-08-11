#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

vector<int> dp;
graph g;

int max_hang(int node) {
	int mx_height = 0;
	for(int child : g[node])
		mx_height = max(mx_height, max_hang(child)), dp[node] += dp[child];
	++mx_height;
	dp[node] = max(dp[node], mx_height);
	return mx_height;
}

void solve() {
	int n; cin >> n;
	g.resize(n+1), dp.resize(n+1);
	fill(dp.begin(), dp.end(), 0);

	int p;
	for(int i = 2; i <= n; ++i)
		cin >> p, g[p].push_back(i);
	max_hang(1);
	cout << dp[1] << '\n';
}



signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

