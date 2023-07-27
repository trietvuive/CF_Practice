#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll n, dp[5005][5005], sum[5005][5005], MOD = 1e9 + 7;
string s;
void solve() {
	cin >> n >> s;
	s = '+' + s;
	for(int i = 1; i <= n; ++i) dp[1][i] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j >= 1; --j) {
			if(s[j] == '0') dp[j][i] = 0;
			else {
				dp[j][i] = (dp[j][i] + sum[j-1][min(i-j, j-1)]) % MOD;
				int len = i - j + 1, match_idx = j - len;
				if(match_idx > 0 && s.substr(j, len) > s.substr(match_idx, len)) {
					dp[j][i] = (dp[j][i] + dp[match_idx][j-1]) % MOD;
				}
			}

			sum[i][i-j+1] = (sum[i][i-j] + dp[j][i]) % MOD;
		}
	}

	ll ans = 0;
	for(int i = 1; i <= n; ++i) ans = (ans + dp[i][n]) % MOD;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

