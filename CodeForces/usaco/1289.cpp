#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n, k; cin >> n >> k;
	ll last_day; cin >> last_day;
	ll ans = k+1;
	for(int i = 1; i < n; ++i) {
		ll day; cin >> day;
		ans += min(k+1, day-last_day);
		last_day = day;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

