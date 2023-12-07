#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
template<class T>
using graph = vector<vector<T>>;
constexpr ll MOD = 1e9 + 7;

ll dp[100005][2];

void recurse(int node, graph<int>& g, int parent = -1) {
	ll white = 1, black = 1;
	for(int child : g[node]) {
		if(child != parent) {
			recurse(child, g, node);
			black = (black * dp[child][0]) % MOD;
			white = (white * (dp[child][0] + dp[child][1])) % MOD;
		}
	}
	dp[node][0] = white;
	dp[node][1] = black;
}
void solve() {
	int n; cin >> n;
	int x,y;

	graph<int> g(n+1);
	for(int i = 0; i < n-1; ++i)
		cin >> x >> y, g[x].push_back(y), 
					   g[y].push_back(x);

	recurse(1, g);
	ll ans = (dp[1][0] + dp[1][1]) % MOD;
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

