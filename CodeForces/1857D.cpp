#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	ll n, mx_diff = INT_MIN; cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i], mx_diff = max(mx_diff, a[i] - b[i]);

	vector<int> ans;
	for(int i = 0; i < n; ++i)
		if(a[i] >= b[i] + mx_diff) ans.push_back(i+1);

	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

