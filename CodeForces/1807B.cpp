#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	int even = 0, odd = 0;
	for(int i = 0; i < n; ++i) {
		int a; cin >> a;
		if(a % 2) odd += a;
		else even += a;
	}

	if(even > odd) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

