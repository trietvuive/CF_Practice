#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	int last; cin >> last;
	if(last == 1) ++last;

	for(int i = 1; i < n; ++i) {
		cout << last << ' ';
		int x; cin >> x;
		if(x == 1) ++x;
		if(x % last == 0) ++x;
		last = x;
	}
	cout << last << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

