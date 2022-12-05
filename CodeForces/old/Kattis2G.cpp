#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; 
	while(cin >> k >> n) {
		double dp[n+1][k+1];
		memset(dp, 0, sizeof(dp));

		++k;
		for(int i = 0; i < k; ++i) 
			dp[0][i] = (double)1/k;

		for(int term = 0; term < n; ++term) {
			for(int digit = 0; digit < k; ++digit) {
				for(int d = max(0, digit-1); d < min(k, digit+1); ++d) {
					dp[term+1][d] += dp[term][digit] / k;
				}
			}
		}

		double ans = 0;
		for(int i = 0; i < k; ++i)
			ans += dp[n][i];
		cout << fixed << setprecision(12) << ans << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
