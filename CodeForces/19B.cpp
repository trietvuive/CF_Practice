#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	ll n; cin >> n;
	vector<ll> dp(2003, 1ll << 60);
	dp[0] = 0;

	for(int i = 0; i < n; ++i) {
		ll t,c; cin >> t >> c; ++t;
		for(int j = n; j >= 0; --j) {
			dp[min(n, j + t)] = min(dp[min(n, j + t)], dp[j] + c);
		}
	}
	
	cout << dp[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

