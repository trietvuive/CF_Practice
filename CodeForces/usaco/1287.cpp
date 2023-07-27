#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n, t; cin >> n >> t;
	map<ll, ll> mp;
	
	ll ans = 0;
	ll current_hay = 0, last_day = 0;
	cin >> last_day >> current_hay;

	for(int i = 1; i < n; ++i) {
		ll day, val; cin >> day >> val;

		ll ate = min(current_hay, day - last_day);
		ans += ate;
		current_hay -= ate;
		current_hay += val;
		last_day = day;
	}

	ans += min(current_hay, t - last_day + 1);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

