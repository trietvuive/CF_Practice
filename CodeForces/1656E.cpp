#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void assign(int node, int parent, int weight, vector<int>& ans, graph& g) {
	ans[node] = g[node].size() * weight;
	for (int child : g[node]) {
		if (child == parent) continue;
		assign(child, node, -weight, ans, g);
	}
}

void solve() {
	int n; cin >> n;
	graph g(n+1);
	vector<int> ans(n+1);

	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	assign(1, 0, 1, ans, g);
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

