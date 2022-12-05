#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll tc, n, a, b, q;
ll solve() {
	cin >> n;
	ll square_a = 0, square_b = 0, sum_a = 0, sum_b = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a >> b;
		square_a = (square_a + a*a) % MOD;
		square_b = (square_b + b*b) % MOD;
		sum_a = (sum_a + a) % MOD;
		sum_b = (sum_b + b) % MOD;
	}
	cin >> q;
	ll ans = 0;
	for(int i = 0; i < q; ++i) {
		cin >> a >> b;
		ans = (ans + square_a - 2*a*sum_a + n*a*a) % MOD;
		ans = ((ans % MOD) + MOD) % MOD;
		ans = (ans + square_b - 2*b*sum_b + n*b*b) % MOD;
		ans = ((ans % MOD) + MOD) % MOD;
	}
	return ans;
}
int main() {
	freopen("in/sample.txt", "r", stdin);
	freopen("out/sample.txt", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		ll ans = solve();
		cout << "Case #" << i << ": " << ans << '\n';
	}
}
