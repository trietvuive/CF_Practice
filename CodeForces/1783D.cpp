#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll a[305], MOD = 998244353, MX = 300*300 + 5;
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];


	vector<ll> dp(2*MX + 500, 0);
	dp[a[2] + MX] = 1;

	for(int i = 3; i <= n; ++i) {
		vector<ll> dp_next(2*MX + 500, 0);
		for(int j = 0; j <= 2*300*300; ++j) {
			ll last_val = j - MX;
			dp_next[last_val + a[i] + MX] = (dp_next[last_val + a[i] + MX] + dp[j]) % MOD;
			if(last_val == 0) continue;
			dp_next[-last_val + a[i] + MX] = (dp_next[-last_val + a[i] + MX] + dp[j]) % MOD;
		}
		dp.swap(dp_next);
	}

	ll ans = 0;
	for(int i = 0; i <= 2*MX; ++i) {
		ans = (ans + dp[i]) % MOD;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

