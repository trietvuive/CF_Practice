#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	string a;

	int i = 0;
	while(i < n) {
		char c = s[i];
		++i;
		while(s[i] != c) ++i;

		a += c;
		++i;
	}
	cout << a << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

