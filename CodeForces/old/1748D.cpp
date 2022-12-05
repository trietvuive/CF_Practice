#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll x,y,d,mul = 1; cin >> x >> y >> d;
	while(d % 2 == 0) {
		if(x % 2 || y % 2) {
			cout << -1 << '\n';
			return;
		}
		d /= 2, x /= 2, y /= 2, mul *= 2;
	}

	ll ans = d;
	for(int i = 0; i < 30; ++i) {
		if(ans & (1 << i)) continue;
		ans += (d << i);
	}

	cout << ans * mul << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
