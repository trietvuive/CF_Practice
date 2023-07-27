#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	map<char,int> right;
	set<char> left;

	for(char c : s) ++right[c];

	int ans = right.size();
	for(int i = 0; i < n; ++i) {
		left.insert(s[i]);
		--right[s[i]];
		if(right[s[i]] == 0) right.erase(s[i]);

		ans = max(ans, (int)left.size() + (int)right.size());
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

