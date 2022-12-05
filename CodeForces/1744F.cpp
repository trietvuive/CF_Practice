#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	ll ans = 0;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x] = i;
	}
	int left = mp[0], right = mp[0];
	for(int mex = 1; mex < n; ++mex) {
		int next_idx = mp[mex];
		while(next_idx < left) {
			int sz = right - left + 1;
			ans += min(n - right, max(0, 2 * mex - sz + 1));
			--left;
		}
		while(right < next_idx) {
			int sz = right - left + 1;
			ans += min(left + 1, max(0, 2 * mex - sz + 1));
			++right;
		}
	}
	++ans;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}
