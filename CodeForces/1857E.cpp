#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<ll> p(n);
	for(int i = 0; i < n; ++i) cin >> p[i];
	vector<ll> orig = p;
	sort(p.begin(), p.end());

	map<ll, ll> ans;
	ll sm = 0;
	for(int i = 0; i < n; ++i)
		sm += p[i] - p[0] + 1;

	ans[p[0]] = sm;
	for(int i = 1; i < n; ++i) {
		ll diff = p[i] - p[i-1];
		sm += (i - (n-i)) * diff;
		ans[p[i]] = sm;	
	}

	for(int i = 0; i < n; ++i)
		cout << ans[orig[i]] << " \n"[i == n-1];
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

