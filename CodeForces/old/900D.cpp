#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
map<ll, ll> mp;

ll modpow(ll base, int p) {
	ll res = 1;
	while (p > 0) {
		if (p % 2 == 1) {
			res *= base;
			res %= MOD;
		}

		base *= base;
		base %= MOD;

		p /= 2;
	}

	return res;
}

ll f(ll n) {
	if(n == 1) return 1;
	if(mp.find(n) != mp.end()) return mp[n];

	ll ans = 0;
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			ans = (ans + f(i)) % MOD;
			if(i * i != n) ans = (ans + f(n/i)) % MOD;
		}
	}

	ans += f(1);
	ans = (modpow(2, n-1) - ans + MOD) % MOD;
	return mp[n] = ans;
}

void solve() {
	ll x,y; cin >> x >> y; 
	if(y % x) cout << 0 << '\n';
	else cout << f(y/x) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solve();
}
