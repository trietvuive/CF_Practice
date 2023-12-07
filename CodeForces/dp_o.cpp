#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T>
using graph = vector<vector<T>>;
constexpr ll MOD = 1e9 + 7;

int turn_off_bit(int n, int k) {
	return n & ~(1 << (k-1));
}

void solve() {
	int n; cin >> n;
	graph<int> g(n);
	int temp;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> temp;
			if(temp == 1) g[i].push_back(j);
		}
	}

	unordered_map<int,ll> dp;
	dp[0] = 1;

	for(int i = 0; i < n; ++i) {
		unordered_map<int,ll> temp;
		for(int child : g[i]) {
			for(auto& [mask, value] : dp) {
				if((mask & (1<<child)) == 0) 
					temp[mask | (1<<child)] = (temp[mask | (1<<child)] + value) % MOD;
			}
		}

		dp = temp;
	}

	cout << dp[(1<<n) - 1];
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

