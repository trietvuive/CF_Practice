#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int ans = 0;
	for(int i = 0; i < 6; ++i) {
		int x; cin >> x;
		ans += x;
	}
	cout << ans*5 << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

