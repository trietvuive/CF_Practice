#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> q(n+1);
	
	int largest_idx = -1, largest = -1;
	for(int i = 1; i <= n; ++i) {
		cin >> q[i];
		if(q[i] > largest) largest = q[i], largest_idx = i;
	}

	vector<int> supervisor(n+1, INT_MAX);
	int m; cin >> m;
	for(int i = 0; i < m; ++i) {
		int a,b,c; cin >> a >> b >> c;
		supervisor[b] = min(supervisor[b], c);
	}

	ll sm = 0;
	for(int i = 1; i <= n; ++i) {
		if(supervisor[i] == INT_MAX && i != largest_idx) {
			cout << -1 << '\n';
			return;
		}
		else if(i != largest_idx) sm += supervisor[i];
	}
	cout << sm << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

