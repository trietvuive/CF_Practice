#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

void solve() {
	string s; cin >> s;
	if(s.size() % 2 == 1) s = '0' + s;

	int n = s.size();
	string ans = string(n/2, '7') + string(n/2, '4');
	if(ans < s) 
		ans = '7' + (ans + '4'), s = '0' + ('0' + s);

	int l = 0, r = s.size()/2;
	while(l <= r && r < s.size()) {
		swap(ans[l], ans[r]);
		if(ans < s)
			swap(ans[l], ans[r]), --r;

		++l, ++r;
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

