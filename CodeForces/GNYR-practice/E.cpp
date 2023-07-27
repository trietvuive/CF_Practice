#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	ll p,q,n,m; cin >> p >> q >> n >> m;
	for(ll r = 1; r <= m; ++r) {
		for(ll g = 1; g <= m; ++g) {
			if(r+g < n || r+g > m) continue;
			ll numerator = 2*r*g;
			ll denominator = (r+g)*(r+g-1);
			ll div = gcd(numerator, denominator);
			numerator /= div, denominator /= div;

			if(numerator == p && denominator == q) {
				cout << r << ' ' << g << '\n';
				return;
			}
		}
	}
	cout << "NO SOLUTION\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

