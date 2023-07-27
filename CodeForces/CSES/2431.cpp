#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll xpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void solve() {
	ll q; cin >> q;
	ll digits = 1, cnt = 9;
	while(q > cnt) {
		q -= cnt;
		digits++;
		cnt = 9 * digits * xpow(10, digits - 1);
	}

	--q;
	ll x = q/digits, y = q%digits;
	ll ans = xpow(10, digits - 1) + x;
	string s = to_string(ans);
	cout << s[y] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

