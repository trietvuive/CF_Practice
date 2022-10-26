#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void solve() {
	int n,c; cin >> n >> c;
	map<int,int> s;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		++s[x];
	}
	int ans = n;
	for(const auto& [k,v] : s) {
		ans -= max(0, v - c);
	}

	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
