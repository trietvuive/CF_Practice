#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int longest_prefix(const vector<int>& a, const vector<int>& b) {
	int n = a.size(), idx = 0;
	while (idx < n && a[idx] == b[idx]) idx++;
	return idx;
}

void solve() {
	int n,m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));

	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) 
			cin >> a[i][j], a[i][j]--;

	vector<vector<int>> inv(n, vector<int>(m));
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) 
			inv[i][a[i][j]] = j;

	sort(inv.begin(), inv.end());

	for(int i = 0; i < n; ++i) {
		int idx = lower_bound(inv.begin(), inv.end(), a[i]) - inv.begin();
		int mx = 0;
		if(idx > 0) mx = max(mx, longest_prefix(a[i], inv[idx-1]));
		if(idx < n) mx = max(mx, longest_prefix(a[i], inv[idx]));

		cout << mx << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

