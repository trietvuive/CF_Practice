#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, 0));
	vector<ll> x(n);
	for (int i = 0; i < n; i++) 
		cin >> x[i];

	if(x[0] == 0)
		for(int i = 1; i <= m; i++)
			dp[1][i] = 1;
	else 
		dp[1][x[0]] = 1;

	for(int i = 2; i <= n; ++i) {
		ll a = x[i-1];
		if(a == 0) 
			for(int j = 1; j <= m; ++j)
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
		else 
			dp[i][a] = (dp[i-1][a-1] + dp[i-1][a] + dp[i-1][a+1]) % MOD;
	}

	ll ans = 0;
	for(int i = 1; i <= m; ++i)
		ans = (ans + dp[n][i]) % MOD;

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

