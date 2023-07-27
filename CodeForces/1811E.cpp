#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll k; cin >> k;
	vector<int> v;
	while(k) {
		int last = k % 9; k /= 9;
		v.push_back(last + (last >= 4));
	}
	reverse(v.begin(), v.end());
	for(int i : v) cout << i;
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

