#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	map<int, vector<string>> mp;
	string s;
	for(int i = 0; i < 2*(n-1); ++i)
		cin >> s, mp[s.size()].push_back(s);

	bool palin = true;
	for(auto& [_, v] : mp) {
		string a = v[0], b = v[1];
		reverse(a.begin(), a.end());
		if(a != b) palin = false;
	}

	if(palin) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

