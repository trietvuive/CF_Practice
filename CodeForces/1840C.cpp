#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n,k,q; cin >> n >> k >> q;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	ll ans = 0;
	int count = -k+1;
	for(int i = 0; i < n; ++i) {
		if(a[i] <= q) ans += max(0, ++count);
		else count = -k+1;
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

