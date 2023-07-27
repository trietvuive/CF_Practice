#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll MOD = 998244353, fact[100005];

ll inv(ll a) {
	if(a == 1) return 1;
	return inv(MOD % a) * (MOD - MOD/a) % MOD;
}

ll nCk(ll n, ll k) {
	return fact[n] * inv(fact[k]) % MOD * inv(fact[n-k]) % MOD;
}


void solve() {
	int n; cin >> n;
	string s; cin >> s;
	ll group = 0, zero = 0;

	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') ++zero;
		else if(i + 1 < n && s[i+1] == '1') 
			++group, ++i;
	}
	cout << nCk(zero + group, group) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	fact[0] = 1;
	for(int i = 1; i < 100005; ++i) fact[i] = fact[i-1] * i % MOD;
	int tc; cin >> tc;
	while(tc--) solve();
}

