#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

bool match(string& s, int start) {
	map<char, int> mp;
	for(int i = 0; i < s.size(); ++i) {
		if(mp.find(s[i]) != mp.end() && mp[s[i]] != start) return false;
		mp[s[i]] = start;
		start ^= 1;
	}
	return true;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	if(match(s, 0) || match(s, 1))
		cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

