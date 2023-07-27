#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string s; cin >> s;
	int ans = 1;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '?')
			ans = ans * (i == 0 ? 9 : 10);

	if(s[0] == '0') cout << 0 << '\n';
	else cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

