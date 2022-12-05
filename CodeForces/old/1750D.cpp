#include<bits/stdc++.h>
using ll = long long;
using namespace std;

vector<ll> prime(int n) {
	vector<ll> p;
	for(ll i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			p.push_back(i);
			while(n % i == 0) {
				n /= i;
			}
		}
	}
	if(n > 1) p.push_back(n);

	return p;
}

void solve() {
	ll n, k, prev, ans = 1, MOD = 998244353;
	cin >> n >> k >> prev;
	for(int i = 1; i < n; ++i) {
		ll x; cin >> x;
		if(prev % x) ans = 0;
		if(ans == 0) continue;

		vector<ll> p = prime(prev / x);
		int t = 0;
		for(int mask = 0; mask < (1 << p.size()); ++mask) {
			ll cur = 1, sign = 1;
			for(int j = 0; j < p.size(); ++j) {
				if(mask & (1 << j)) cur *= p[j], sign *= -1;
			}
			if(cur > k) continue;
			t = (t + sign * k / x / cur + MOD) % MOD;
		}
		ans = (1ll * ans * t) % MOD;
		prev = x;
	}
	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}
