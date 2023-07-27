#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;
int a[100005], n;

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	set<int> curr;

	int max_value = 1 << 8;
	vector<char> has_pref(max_value);
	has_pref[0] = true;
	int cur_xor=  0, ans = 0;

	for(int i = 0; i < n; ++i) {
		cur_xor ^= a[i];
		for(int prefix = 0; prefix < max_value; ++prefix) {
			if(has_pref[prefix]) ans = max(ans, prefix ^ cur_xor);
		}
		has_pref[cur_xor] = true;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

