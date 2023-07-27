#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll max_size(ll left, ll right) {
	ll cnt = 0;
	while(left < right)
		left *= 2, ++cnt;
	return cnt;
}

void solve() {
	ll left, right; cin >> left >> right;
	ll mx = max_size(left, right);
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

