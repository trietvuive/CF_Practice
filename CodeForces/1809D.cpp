#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string s; cin >> s;
	int n = s.size();
	vector<ll> left(n, 0), right(n, 0);

	left[0] = s[0] == '1';
	right[n-1] = s[n-1] == '0';
	for(int i = 1; i  < n; ++i)
		left[i] = left[i-1] + (s[i] == '1');

	for(int i = n-2; i >= 0; --i)
		right[i] = right[i+1] + (s[i] == '0');

	ll ans = 1e18;
	ll delete_cost = 1e12 + 1, swap_cost = 1e12;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') continue;
		ll deletion = left[i] - 1 + right[i], swap = 0;
		if(i+1 < n && s[i+1] == '0') --deletion, ++swap;

		ll total_cost = deletion * delete_cost + swap * swap_cost;
		ans = min(ans, total_cost);
	}
	
	// delete all 1
	ans = min(ans, left[n-1] * delete_cost);

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

