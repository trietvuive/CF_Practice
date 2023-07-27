#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n, k, x; cin >> n >> k >> x;
	vector<vector<int>> ans;
	vector<bool> vis(n + 1, false);

	for(int cur = 1; ans.size() < k-1 && cur <= n; ++cur) {
		if(vis[cur] || (cur ^ x) > n || vis[cur ^ x]) continue;

		if(cur == x) ans.push_back({cur});
		else ans.push_back({cur, cur ^ x});
		vis[cur] = vis[x ^ cur] = true;
	}

	ll remain = 0;
	ans.push_back({});
	for(int i = 1; i <= n; ++i) 
		if(!vis[i]) 
			remain ^= i, ans.back().push_back(i);

	if(ans.size() < k || remain != x) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for(auto &v : ans) {
		cout << v.size() << ' ';
		for(auto x : v) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

