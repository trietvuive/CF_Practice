#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	ll n,a,b,ans = 0; cin >> n;
	map<size_t, vector<ll>> lamps;

	for(int i = 0; i < n; ++i)
		cin >> a >> b, lamps[a].push_back(b);

	for(auto& [k, lamp] : lamps) {
		sort(lamp.begin(), lamp.end(), greater<>());
		for(int i = 0; i < min(k, lamp.size()); ++i) ans += lamp[i];
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

