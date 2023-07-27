#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int dp[505][505];
int c[505];
void solve() {
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) cin >> c[i];

	for(int i = n; i >= 1; --i) {
		for(int j = 1; j <= n; ++j) {
			if(i > j) continue;
			if(i == j) dp[i][j] = 1;
			else {
				dp[i][j] = 1 + dp[i+1][j];
				if(c[i] == c[i+1]) dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);

				for(int k = i+2; k <= j; ++k) {
					if(c[i] == c[k]) dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
				}
			}
		}
	}

	cout << dp[1][n] << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

