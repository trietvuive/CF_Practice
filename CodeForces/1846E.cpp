#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;
set<ll> nums;

void solve() {
	ll n; cin >> n;
	if(n < 3) {
		cout << "NO\n";
		return;
	}

	ll d = 4*n - 3;
	ll sq = sqrtl(d);

	if(sq * sq != d) sq = -1;
	if(sq != -1 && (sq - 1) % 2 == 0 && (sq - 1) / 2 > 1) 
		cout << "YES\n";
	else if(nums.count(n))
		cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	for(ll k = 2; k <= 1e6; ++k) {
		ll val = 1 + k, p = k*k;
		for(int degree = 3; degree <= 63; ++degree) {
			val += p;
			if(val > 1e18) break;
			nums.insert(val);
			if(p > (ll)(1e18)/k) break;
			p *= k;
		}
	}

	int tc; cin >> tc;
	while(tc--) solve();
}

