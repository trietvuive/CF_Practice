#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	int mx = 0, j = 0;
	vector<int> a(n+1);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(abs(a[i]) > mx) mx = abs(a[i]), j = i;
	}

	if(mx == 0) {
		cout << 0 << '\n';
		return;
	}

	cout << 2*n-1 << '\n';
	for(int i = 1; i <= n; ++i) cout << i << ' ' << j << '\n';
	if(a[j] > 0) 
		for(int i = 2; i <= n; ++i) cout << i << ' ' << i-1 << '\n';
	else 
		for(int i = n-1; i >= 1; --i) cout << i << ' ' << i+1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

