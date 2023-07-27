#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	string s; cin >> s;
	int ans = s.size();
	for(int i = 1; i < s.size() - 1; ++i) {
		if(s[i] == 'O') {
			int match = 1 + (s[i-1] == 'M') + (s[i+1] == 'O');
			ans = min(ans, (int)s.size() - match);
		}
	}

	if(ans == s.size()) cout << -1 << '\n';
	else cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

