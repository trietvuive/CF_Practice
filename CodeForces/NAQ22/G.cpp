#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

bool vis[100005], vis2[100005], cycles[100005];
ll dp[100005];

struct DSU {
    int n;
    vector<int> par;
    vector<int> size;
    DSU(int n) : n(n), par(n+1), size(n+1) {
        std::iota(begin(par), end(par), 0);
        std::fill(begin(size), end(size), 1);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        par[b] = a;
        size[a] += size[b];
    }
};

bool find_cycle(int v, graph& g) {
	if(vis2[v]) return true;

	vis2[v] = true;
	for(int child : g[v]) {
		if(vis[child]) continue;
		if(find_cycle(child, g)) {
			cycles[v] = true;
		}
	}
	vis[v] = true;

	return cycles[v];
}

void dp_dfs(int v, graph& g) {
	ll ans = 1;
	bool has_child = false, on_cycle = cycles[v];
	for(int child : g[v]) {
		if(!cycles[child]) {
			dp_dfs(child, g);
			ans = (ans * dp[child]) % MOD;
			has_child = true;
		}
	}

	dp[v] = has_child ? (ans + !cycles[v]) % MOD : 2 - on_cycle;
}

void solve() {
	int n; cin >> n;
	graph g(n+1);
	DSU dsu(n+1);

	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		g[x].push_back(i), dsu.merge(x, i);
	}

	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			find_cycle(i, g);
		}
	}

	map<int, ll> product;
	for(int i = 1; i <= n; ++i) {
		if(cycles[i]) {
			dp_dfs(i, g);
			ll leader = dsu.find(i);
			if(product.count(leader) == 0) product[leader] = 1;

			product[leader] = (product[leader] * dp[i]) % MOD;
		}
	}

	// for(int i = 1; i <= n; ++i) printf("%d %d\n", i, dp[i]);

	ll ans = 1;
	for(auto [k, v] : product) {
		ans = (ans * (v+1)) % MOD;
	}
	--ans;

	if(product.size() == 1) cout << product.begin()->second << endl;
	else cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

