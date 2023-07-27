#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	sort(a.begin(), a.end());
	ll sm = 1;
	bool ok = a[0] == 1;

	for(int i = 1; i < n; ++i) {
		if(a[i] > sm) ok = false;
		sm += a[i];
	}

	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

