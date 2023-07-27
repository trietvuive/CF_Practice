#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	sort(a.begin(), a.end());

	ll left = 0, right = 1e9;
	while(left < right) {
		ll m = (left+right)/2;
		int l = 1, r = n;
		while(l <= n && a[l] - a[1] <= 2 * m) ++l;
		while(r >= 1 && a[n] - a[r] <= 2 * m) --r;

		if(l > r || a[r] - a[l] <= 2 * m) right = m;
		else left = m+1;
	}

	cout << left << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

