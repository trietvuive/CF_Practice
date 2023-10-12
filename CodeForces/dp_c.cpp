#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	int last_a = 0, last_b = 0, last_c = 0;

	for(int i = 0; i < n; ++i) {
		int a,b,c; cin >> a >> b >> c;
		int next_last_a = max(last_b, last_c) + a;
		int next_last_b = max(last_a, last_c) + b;
		last_c = max(last_a, last_b) + c;
		last_b = next_last_b, last_a = next_last_a;
	}
	
	cout << max({last_a, last_b, last_c});
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

