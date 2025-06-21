#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

const ll MOD = 1e9 + 7, N = 2e5 + 5;

vector<int> leafs;
int lca;
int pw[N];

void dfs(int u, int parent, int height, graph &g) {
    if(g[u].size() > 2) lca = height;

    bool leaf = true;
    for(int v : g[u]) {
        if(v != parent) {
            dfs(v, u, height + 1, g);
            leaf = false;
        }
    }
 
    if(leaf) leafs.push_back(height);
}

void solve() {
	int n; cin >> n;
    graph g(n+1);
    leafs.clear(); lca = -1;

    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    g[1].push_back(0);
    dfs(1, 0, 1, g);
    if(leafs.size() == 1) {
        cout << pw[n] << '\n';
    } else if(leafs.size() > 2) {
        cout << 0 << '\n';
    } else {
        int diff = abs(leafs[0] - leafs[1]);
        int x = diff + lca;
        if(diff) cout << (pw[x] + pw[x-1]) % MOD << '\n';
        else cout << (2 * pw[x]) % MOD << '\n';
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; cin >> tc;
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = (pw[i-1] * 2) % MOD;
	while(tc--) solve();
}