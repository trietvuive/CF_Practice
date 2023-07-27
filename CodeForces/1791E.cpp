#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	ll flip = -a[0] + -a[1], no_flip = a[0] + a[1];
	for(ll i = 2; i < n; ++i) {
		ll new_flip = max(flip + 2*a[i-1], no_flip - 2*a[i-1]) - a[i];
		ll new_no_flip = max(flip, no_flip) + a[i];
		flip = new_flip;
		no_flip = new_no_flip;
	}
	cout << max(flip, no_flip) << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

