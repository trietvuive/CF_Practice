#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int nxt[200005];
vector<int> back[200005];

struct DSU {
	vector<int> par, sz;
	DSU(int n) : par(n+1), sz(n+1, 1) {
		iota(par.begin(), par.end(), 0);
	}
	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (sz[x] < sz[y]) swap(x, y);
		par[y] = x;
		sz[x] += sz[y];
	}
};

void process_query(int u, int v) {

}

void solve() {
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> nxt[i], back[nxt[i]].push_back(i);

}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

