#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string s; cin >> s;

	int max_val = 0;
	map<char, int> mp;
	for(char c : s) max_val = max(max_val, ++mp[c]);
	
	if(max_val == 4) cout << -1 << '\n';
	else cout << max(4, 2 * max_val) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

