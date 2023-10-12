#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 2e9;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> dp(n+1, INF), h(n+1);
	dp[1] = 0;

	for(int i = 1; i <= n; ++i) {
		cin >> h[i];

		for(int j = i-k; j < i; ++j)
			if(j > 0)
				dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
	}

	cout << dp[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

