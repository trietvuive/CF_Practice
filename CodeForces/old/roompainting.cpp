#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
	int n,m; cin >> n >> m;
	set<ll> s;
	for(int i = 0; i < n; ++i) {
		ll x; cin >> x;
		s.insert(x);
	}

	ll ans = 0;
	for(int i = 0; i < m; ++i) {
		ll x; cin >> x;
		ans += (*s.lower_bound(x) - x);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
}
