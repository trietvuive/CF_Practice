#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n,k,x; cin >> n >> k >> x;
	vector<vector<ll>> ans(k);
	vector<bool> vis(n+1);

	ll cur = 1, i = 0;
	for(; i < k; ++i) {
		if(!vis[cur]) {
			ans[i].push_back(cur);
			ans[i].push_back(x ^ cur);
			vis[cur] = vis[x ^ cur] = true;
			++i;
		}
		++cur;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

