#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n, k; cin >> n >> k;
	vector<ll> dp(k+1, 0);
	dp[k] = 1;

	for(int i = 0; i < n; ++i) {
		int a; cin >> a;
		vector<ll> temp(k+1, 0);
		int cumulative_sum = 0;

		for(int i = k; i >= 0; --i) {
			cumulative_sum += dp[i];
			if(i + a + 1 <= k) cumulative_sum -= dp[i+a+1];
			cumulative_sum = (cumulative_sum + MOD) % MOD;
			temp[i] = cumulative_sum;
		}

		dp = temp;
	}

	cout << dp[0] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

