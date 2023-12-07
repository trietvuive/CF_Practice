#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> free(n), apps(m);
	for(int i = 0; i < n; ++i)
		cin >> free[i];
	for(int i = 0; i < m; ++i)
		cin >> apps[i];

	sort(free.begin(), free.end());
	sort(apps.begin(), apps.end());

	int ans = 0, free_idx = 0;
	for(int app : apps) {
		while(free_idx < n && free[free_idx] < app-k)
			++free_idx;
		if(free_idx < n && free[free_idx] <= app+k) ++ans, ++free_idx;
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

