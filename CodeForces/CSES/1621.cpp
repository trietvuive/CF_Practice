#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	set<int> s;
	int n, x;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> x, s.insert(x);

	cout << s.size() << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

