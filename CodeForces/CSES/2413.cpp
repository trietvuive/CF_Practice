#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

constexpr int MAX = 1e6 + 5;
ll dp[MAX];
ll MOD = 1e9 + 7;

void populate() {
	ll a = 1, b = 1;
	dp[1] = 2;
	for(int i = 2; i < MAX; ++i) {
		ll nxt_a = (2 * a + b) % MOD, nxt_b = (a + 4*b) % MOD;
		dp[i] = (nxt_a + nxt_b) % MOD;
		a = nxt_a, b = nxt_b;
	}
}

ll ans(ll n) {
	return dp[n];
}

void solve() {
	int n; cin >> n;
	cout << ans(n) << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	populate();
	int tc; cin >> tc;
	while(tc--) solve();
}

