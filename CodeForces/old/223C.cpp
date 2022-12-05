#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ar[2005], n, k, MOD = 1e9 + 7, coeff[2005];

// assuming gcd(a, mod) = 1
ll inv(ll a, ll b) {
	return a == 1 ? 1 : b - inv(b%a, a) * b / a;
}


void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> ar[i];

	--k;
	coeff[0] = 1;
	for(ll i = 1; i < n; ++i) {
		// coeff[i] = coeff[i-1] * (i+k) / i
		coeff[i] = ((coeff[i-1] * (i+k)) % MOD * inv(i, MOD)) % MOD;
	}

	for(int i = 0; i < n; ++i) {
		ll ans = 0;
		for(int j = 0; j <= i; ++j) {
			ans = (ans + coeff[i-j] * ar[j]) % MOD;
		}
		cout << ans << ' ';
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
