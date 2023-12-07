#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<ll> a(n+1), sm(n+1);
	vector<vector<ll>> dp(n+1, vector<ll>(n+1, 1e14));

	a[0] = sm[0] = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], sm[i] = a[i] + sm[i-1], dp[i][i] = 0;

	for(int right = 1; right <= n; ++right) {
		for(int left = right-1; left > 0; --left) {
			for(int slider = left; slider < right; ++slider) {
				ll left_slime = sm[slider] - sm[left-1];
				ll right_slime = sm[right] - sm[slider];
				dp[left][right] = min(dp[left][right], left_slime + right_slime + 
													   dp[left][slider] + dp[slider+1][right]);
			}
		}
	}
	cout << dp[1][n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

