#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	ll ans = 1, j = 0;
	while(k--) {
		while(j < n && a[j] <= ans + j)
			++j;
		ans += j;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

