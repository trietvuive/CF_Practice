#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> dp(m+1, 0);

	for(int i = 0; i < n; ++i) {
		int sz; cin >> sz;
		vector<int> a(sz);
		for(int j = 0; j < sz; ++j) cin >> a[j];

		vector<int> prefix(sz+1), suffix(sz+1), small_dp(sz+1, 0);
		prefix[0] = suffix[0] = 0;
		for(int j = 1; j <= sz; ++j) 
			prefix[j] = prefix[j-1] + a[j-1],
			suffix[j] = suffix[j-1] + a[sz-j];

		for(int left = 0; left <= sz; ++left)
			for(int right = 0; right <= sz-left; ++right) 
				small_dp[left+right] = max(small_dp[left+right], prefix[left] + suffix[right]);
		
		for(int j = m; j >= 0; --j) 
			for(int curr = max(0, j - sz); curr <= j; ++curr)
				dp[j] = max(dp[j], dp[curr] + small_dp[j - curr]);
	}

	cout << dp[m] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

