#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	vector<int> a(n-1);
	for(int i = 0; i < n-1; ++i) cin >> a[i];

	vector<int> ans{a[0], 0};
	for(int i = 1; i < n-1; ++i) {
		int last = ans.back();
		if(last == a[i]) ans.push_back(0);
		if(last < a[i]) ans.push_back(a[i]);
		if(last > a[i]) swap(ans[i], ans[i-1]), ans.push_back(a[i]);
	}

	for(int i = 0; i < n; ++i)
		cout << ans[i] << " \n"[i == n-1];
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

