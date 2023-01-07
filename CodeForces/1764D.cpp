#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll c[5005][5005], n, p, fac[5005];

void init() {
	c[0][0] = 1;
	for(ll i = 1; i <= 5000; i++) {
		c[i][0] = 1;
		for(ll j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
		}
	}
	fac[0] = fac[1] = 1;
	for(ll i = 2; i <= 5000; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
}

void solve() {
	cin >> n >> p;
	init();
	int t = n/2;
	ll ans = 0;
	for(int i = t; i <= n-1; ++i) {
		if((n&1) && i == n-1) break;
		int upper = i == n-1 ? n-i-1 : n-i-2;
		for(int j = 0; j <= upper; ++j)
			ans = (ans + n * (2*t-i) * c[upper][j] % p * fac[i+j-1]) % p;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

