#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n; 
string s;

int count(size_t start_idx) {
	vector<int> cnt(10, 0);
	int distinct_count = 0, ans = 0, max_cnt = 0;
	for(int i = start_idx; i < min(s.size(), start_idx + 101); ++i) {
		if(cnt[s[i] - '0'] == 0) ++distinct_count;
		max_cnt = max(max_cnt, ++cnt[s[i] - '0']);
		if(distinct_count >= max_cnt) ++ans;
	}
	return ans;
}

void solve() {
	cin >> n >> s;
	ll ans = 0, prev = 0, balance = 0;

	for(int i = 0; i < n; ++i) {
		ans += count(i);
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
