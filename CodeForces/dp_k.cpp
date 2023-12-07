#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> stones(n);
	vector<bool> dp(k+1, true);
	dp[0] = false;

	for(int i = 0; i < n; ++i) cin >> stones[i];

	for(int i = 1; i <= k; ++i) {
		dp[i] = false;
		for(int stone : stones) {
			if(i >= stone && !dp[i-stone])
				dp[i] = true;
		}
	}

	cout << (dp[k] ? "First" : "Second") << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

