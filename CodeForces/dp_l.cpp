#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	vector<vector<ll>> dp(n, vector<ll>(n, 0));

	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int right = 0; right < n; ++right) {
		dp[right][right] = a[right];
		for(int left = right-1; left >= 0; --left) {
			dp[left][right] = max(a[left] - dp[left+1][right], 
								  a[right] - dp[left][right-1]);
		}
	}

	cout << dp[0][n-1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

