#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	int mx = 0, ans = 0, element = 0;
	cin >> mx;
	for(int i = 1; i < n; ++i) {
		cin >> element;
		mx = max(mx, element);
		if(mx != element) ans = mx;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

