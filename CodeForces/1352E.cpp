#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<bool> exist(n+1, false);
	vector<int> a(n);

	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int left = 0; left < n; ++left) {
		int sm = a[left];
		for(int right = left+1; right < n; ++right) {
			sm += a[right];
			if(sm <= n) exist[sm] = true;
		}
	}

	int ans = 0;
	for(int i : a)
		if(exist[i])
			++ans;
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

