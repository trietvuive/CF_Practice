#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;

void solve() {
	int n, k; cin >> n >> k;
	vector<ll> dp(64);

	for(int i = 0; i < n; ++i) {
		int element; cin >> element;
		for(int j = 0; j < 64; ++j) {
			dp[j & element] = (dp[j & element] + dp[j]) % MOD;
		}
		++dp[element];
	}

	ll ans = 0;
	for(int i = 0; i < 64; ++i)
		if(__builtin_popcount(i) == k)
			ans = (ans + dp[i]) % MOD;

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

