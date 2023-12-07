#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n,m; cin >> n >> m;
	string s;
	vector<ll> dp(m, 0);
	dp[0] = 1;
	
	for(int i = 0; i < n; ++i) {
		cin >> s;
		for(int j = 0; j < m; ++j) {
			if(s[j] == '#') dp[j] = 0;
			else if(j > 0) dp[j] = (dp[j] + dp[j-1]) % MOD;
		}
	}

	cout << dp[m-1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

