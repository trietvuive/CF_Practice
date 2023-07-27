#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
#define int ll

void solve() {
	int n,k; cin >> n >> k;
	int total = 0;
	vector<int> left(n), right(n);
	for(int i = 0; i < n; ++i) cin >> left[i];
	for(int i = 0; i < n; ++i) cin >> right[i], total += right[i] - left[i] + 1;

	if(total < k) {
		cout << -1 << '\n';
		return;
	}

	vector<pair<int,int>> segs;
	for(int i = 0; i < n; ++i) segs.emplace_back(left[i], right[i]);

	sort(segs.begin(), segs.end());
	int current_cell = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		// move there. skip single if possible
		if(segs[i].first == segs[i].second && total - 1 >= k) {
			--total;
			continue;
		}

		ans += segs[i].first - current_cell;

		int stop = min(segs[i].second, segs[i].first + k - 1);
		ans += 2 + stop - segs[i].first;
		k -= stop - segs[i].first + 1;
		current_cell = stop;
		if(k <= 0) break;
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

