#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll a[55];

// assume b > a
unordered_set<ll> get_all_x(ll a, ll b) {
	ll diff = b - a;
	unordered_set<ll> res;
	for(ll i = 1; i * i < diff; ++i) {
		ll j = diff / i;
		if(diff % i || (i+j) % 2) continue;
		ll mid = (i+j) / 2, x = mid * mid;

		if(x >= b)
			res.insert(x - b);
	}
	return res;
}

void solve() {
	ll n; cin >> n;
	ll squareness = 0;
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n; ++i) {
		unordered_map<ll, ll> x_cnt;
		for(int j = i+1; j < n; ++j) {
			for(ll x : get_all_x(min(a[i], a[j]), max(a[i], a[j]))) {
				squareness = max(squareness, ++x_cnt[x]);
			}
		}
	}
	cout << squareness + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

