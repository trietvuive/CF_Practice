#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll n, total = 0;
bool dfs(int v, const vector<int> &a, vector<int> &path, int t) {
	if(v < 0 || v > n) return true;

	bool jumpout = dfs(v + a[v], a, path, t+1);
	path[v] = jumpout ? t : -1;
	++total;
	return jumpout;
}
void solve() {
	cin >> n;
	vector<int> a(n+1), path(n+1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	total = 0;
	dfs(1, a, path, 0);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
;
}

