#include<bits/stdc++.h>
using namespace std;

void solve() {
	unordered_map<int, int> mp;
	int n; cin >> n;
	int ans = n;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		if(mp.find(x) != mp.end()) {
			ans = min(ans, i - mp[x]);
		}
		mp[x] = i;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
