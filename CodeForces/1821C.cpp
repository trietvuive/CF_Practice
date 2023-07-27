#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

const int MX = 200005;
int dp[MX];

void solve() {
	string s; cin >> s;
	int n = s.size();
	int ans = n;
	for(char c = 'a'; c <= 'z'; ++c) {
		int mx = 0;
		for(int start = -1, end = 0; end <= n; ++end) {
			if(end == n) {
				mx = max(mx, dp[end-start-1]);
				continue;
			}

			if(s[end] == c) mx = max(mx, dp[end-start-1]), start = end;
		}
		ans = min(ans, mx);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	dp[1] = 1;
	for(int i = 2; i < MX; ++i)
		dp[i] = 1 + dp[i/2];

	int tc; cin >> tc;
	while(tc--) solve();
}

