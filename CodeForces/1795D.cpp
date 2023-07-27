#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 998244353;

ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) res = res * a % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll inv(ll a) {
	return pow_mod(a, MOD - 2);
}

ll nCk(ll n, ll k) {
	ll res = 1;
	for(ll i = 0; i < k; i++) {
		res = res * (n - i) % MOD;
		res = res * inv(i + 1) % MOD;
	}
	return res;
}

void solve() {
	int n; cin >> n;
	ll ans = 1;
	for(int i = 0; i < n/3; ++i) {
		ll a,b,c; cin >> a >> b >> c;
		ll mn = min({a,b,c});
		ll mn_cnt = (mn == a) + (mn == b) + (mn == c);
		ans = (ans * mn_cnt) % MOD;
	}

	ans = (ans * nCk(n/3, n/6)) % MOD;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

