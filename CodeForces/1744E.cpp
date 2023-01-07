#include<bits/stdc++.h>
using namespace std;

int n, d, m1, m2, cnt, sz, path[200005];
vector<int> g[200005];
bool a[200005], b[200005];

void dfs(int x, int parent) {
	path[++sz] = x;
	if(a[x] && sz > d) b[path[sz - d]] = true;
	if(b[x] && sz > d) a[path[sz - d]] = true;
	
	for(int child : g[x]) {
		if(child == parent) continue;
		dfs(child, x), a[x] |= a[child], b[x] |= b[child];
	}
	cnt += a[x] + b[x], --sz;
}

void solve() {
	cin >> n >> d;
	for(int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	a[1] = b[1] = true;
	cin >> m1;
	while(m1--) {
		int x; cin >> x;
		a[x] = true;
	}
	cin >> m2;
	while(m2--) {
		int x; cin >> x;
		b[x] = true;
	}
	dfs(1, 0);
	cout << 2 * (cnt - 2) << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

