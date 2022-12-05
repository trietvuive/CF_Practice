#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n,q,e; cin >> n >> q;
	ll sm = 0, odd = 0, even = 0;
	for(int i = 0; i < n; i++) cin >> e, sm += e,
		++(e % 2 ? odd : even);

	while(q--) {
		ll t, x; cin >> t >> x;
		if(t == 1) {
			sm += x * odd;
			if(x % 2) even = n, odd = 0;
		}

		if(t == 0) {
			sm += x * even;
			if(x % 2) odd = n, even = 0;
		}
		cout << sm << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}
