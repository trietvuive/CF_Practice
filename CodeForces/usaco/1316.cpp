#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string s, cow = "bessie"; cin >> s;
	int idx = 0;

	vector<ll> lens;
	int last = -1;
	for(int i = 0; i < s.size(); ++i) {
		if(cow[idx] == s[i]) ++idx;
		if(idx == cow.size()) lens.push_back(i - last), last = i, idx = 0;
	}
	lens.push_back(s.size() - last);

	ll ans = 0, sz = lens.size() - 1, suffix = 0;
	for(int i = lens.size() - 1; i >= 0; --i) {
		suffix += lens[i];
		ans += sz * suffix;
		--sz;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

