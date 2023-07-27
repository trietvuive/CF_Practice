#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

graph g;
vector<ll> parent, importance, subsize;
vector<set<pair<ll,ll>>> sons;

void dfs(int u, int p = -1) {
	for(int v : g[u]) {
		if(v == p) continue;
		dfs(v, u);
 		importance[u] += importance[v];
		subsize[u] += subsize[v];
		sons[u].emplace(subsize[v], -v);
	}

	parent[u] = p;
}

void rotate(int v) {
	if(sons[v].size() == 0) return;

	int p = parent[v], heavy_son = -sons[v].rbegin()->second;
	sons[p].erase({subsize[v], -v});
	sons[v].erase({subsize[heavy_son], -heavy_son});

	parent[heavy_son] = p, parent[v] = heavy_son;
	subsize[v] -= subsize[heavy_son], subsize[heavy_son] += subsize[v];
	importance[v] -= importance[heavy_son], importance[heavy_son] += importance[v];

	sons[p].insert({subsize[heavy_son], -heavy_son});
	sons[heavy_son].insert({subsize[v], -v});
}


void solve() {
	int n,m,u,v; cin >> n >> m;
	importance.clear(); parent.clear(); subsize.clear(); sons.clear();
	importance.resize(n+1, 0);
	parent.resize(n+1, 0);
	subsize.resize(n+1, 1);
	g.resize(n+1);
	sons.resize(n+1);

	for(int i = 1; i <= n; ++i) cin >> importance[i];
	for(int i = 1; i <= n-1; ++i) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

	dfs(1);

	for(int i = 1; i <= m; ++i) {
		ll op, x; cin >> op >> x;
		if(op == 1) cout << importance[x] << '\n';
		else rotate(x);
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

