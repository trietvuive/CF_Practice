#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	int n, k; cin >> n >> k;
	int a, ans = 0;
	map<int, int> cnt;
	for(int i = 0; i < n; ++i)
		cin >> a, ++cnt[a];

	while(!cnt.empty()) {
		int min_key = cnt.begin()->first;
		auto nxt_pair_key = cnt.upper_bound(k - min_key);
		if(nxt_pair_key == cnt.begin()) {
			ans += cnt[min_key];
			cnt.erase(min_key);
		} else {
			--nxt_pair_key;
			cout << min_key << ' ' << nxt_pair_key->first << endl;
			if(nxt_pair_key->first == min_key) {
				ans += cnt[min_key] / 2;
				cnt[min_key] %= 2;
				if(cnt[min_key] == 0) cnt.erase(min_key);
			} else {
				int pair_cnt = min(nxt_pair_key->second, cnt[min_key]);
				ans += pair_cnt;
				cnt[min_key] -= pair_cnt;
				if(cnt[min_key] == 0)
					cnt.erase(min_key);

				nxt_pair_key->second -= pair_cnt;
				if(nxt_pair_key->second == 0)
					cnt.erase(nxt_pair_key);
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

