#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<double> coins(n+1);
	coins[0] = 1;

	double p;
	for(int i = 0; i < n; ++i) {
		cin >> p;
		for(int j = n; j >= 0; --j)
			coins[j] = coins[j] * (1-p) + (j > 0 ? coins[j-1] * p : 0);
	}

	double ans = 0;
	for(int i = n/2+1; i <= n; ++i) ans += coins[i];

	cout << fixed << setprecision(12) << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

