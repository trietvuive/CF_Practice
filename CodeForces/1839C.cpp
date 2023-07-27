#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];

	if(a[n-1] == 1) 
		cout << "NO\n";
	else {
		cout << "YES\n";
		vector<int> ans;
		for(int idx = n-1; idx >= 0; --idx) {
			if(idx == 0 || a[idx-1] == 0)
				ans.push_back(0);
			else {
				int cnt = 0;
				--idx;
				while(idx >= 0 && a[idx] == 1) ans.push_back(0), ++cnt, --idx;
				++idx;
				ans.push_back(cnt);
			}
		}
		for(int i : ans) cout << i << ' ';
		cout << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

