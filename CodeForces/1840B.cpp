#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	ll n, k; cin >> n >> k;
	++n;
	for(int i = 1; i <= k; ++i) {
		if((1 << i) >= n) {
			cout << n << '\n';
			return;
		}
	}
	cout << (1 << k) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

