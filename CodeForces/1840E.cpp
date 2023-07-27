#include<bits/stdc++.h>
#define diff(i) (S[0][i] != S[1][i])
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	string S[2]; cin >> S[0] >> S[1];
	int t, q, n = S[0].size(); cin >> t >> q;
	int total_diff = 0;

	vector<int> time(q+t+10, 0);

	for(int i = 0; i < n; ++i) total_diff += diff(i);
	for(int curr = 0; curr < q; total_diff += time[++curr]) {
		int type; cin >> type;
		if(type == 1) {
			int idx; cin >> idx; --idx;
			total_diff -= diff(idx);
			time[curr + t] += diff(idx);
		} else if(type == 2) {
			int k1, p1, k2, p2; cin >> k1 >> p1 >> k2 >> p2;
			--p1, --p2;

			int old_diff = diff(p1) + diff(p2);
			swap(S[k1-1][p1], S[k2-1][p2]);
			int new_diff = diff(p1) + diff(p2);
			total_diff += (new_diff - old_diff);
		} else cout << (total_diff ? "NO": "YES") << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

