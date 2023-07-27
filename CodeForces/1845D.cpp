#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	ll cur = 0, mn = 0, cur_left = 0, mn_left = 0;
	for(int i = 0; i < n; ++i) {
		if(cur == 0) cur_left = i;
		cur = min(0ll, cur + a[i]);

		if(cur < mn)
			mn = cur, mn_left = cur_left;
	}

	ll ans = 0;
	for(int i = 0; i < mn_left; ++i)
		ans += a[i];

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

