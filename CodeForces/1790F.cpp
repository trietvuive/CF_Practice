#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

graph g;
vector<int> parent, c;

void dfs(int v) {
	for(int u : g[v]) {
		if(u == parent[v]) continue;
		parent[u] = v;
		dfs(u);
	}
}

void solve() {
	int n; cin >> n;
	g = graph(n);
	parent = vector<int>(n);
	c = vector<int>(n);

	for(int i = 0; i < n; ++i) cin >> c[i], --c[i];
	for(int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	parent[0] = -1;
	dfs(0);

	int ans = n+1;
	vector<int> shortest(n, n+1);
	
	for(int i = 0; i < n; ++i) {
		int node = c[i], dist = 0;
		while(node >= 0 && dist < ans) {
			ans = min(ans, dist + shortest[node]);
			shortest[node] = min(shortest[node], dist);
			node = parent[node];
			++dist;
		}

		if(i > 0) cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

