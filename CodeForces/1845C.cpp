#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

int farthest_idx(int left, int right, int start, const string& s) {
	vector<bool> visited(10, false);
	int n = right-left+1;
	while(n > 0 && start < s.size()) {
		int digit = s[start] - '0';
		if(left <= digit && digit <= right && !visited[digit])
			--n, visited[digit] = true;
		++start;
	}

	if(n > 0) return s.size() + 2;
	return start;
}

void solve() {
	string s, l, r; cin >> s;
	int n; cin >> n;
	cin >> l >> r;
	int idx = 0;
	for(int i = 0; i < l.size(); ++i) {
		idx = farthest_idx(l[i] - '0', r[i] - '0', idx, s);
		if(idx > s.size()) {
			cout << "YES\n";
			return;
		}
	}
	
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

