#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll x[3005], pow2[3005], MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	pow2[0] = 1;
	for (int i = 1; i <= n; ++i)
		cin >> x[i], pow2[i] = pow2[i-1] * 2 % MOD;

	sort(x+1, x+n+1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			ll mid = (x[i] + x[j]) / 2;
			int left = lower_bound(x+1, x+i+1, 2 * x[i] - x[j]) - x - 1;
			int right = lower_bound(x+j+1, x+n+1, 2 * x[j] - x[i]) - x - 2;
			int subset_size = n - (right - left + 1);
			ans = (ans + pow2[subset_size]) % MOD;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

