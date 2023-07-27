#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
	ll x3 = n - x1 + 1, y3 = n - y1 + 1;

	ll cycle1 = min({x1, y1, n - x1 + 1, n - y1 + 1});
	ll cycle2 = min({x2, y2, n - x2 + 1, n - y2 + 1});

	cout << abs(cycle1 - cycle2) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

