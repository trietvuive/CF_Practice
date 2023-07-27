#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

const ll MAX = 2e5 + 5;
ll a[MAX], mn[MAX], sm[MAX];
void solve() {
	ll n, c; cin >> n >> c;

	for (ll i = 1; i <= n; i++) 
		cin >> a[i], mn[i] = min(i, n+1-i) + a[i];

	sort(mn+1, mn+n+1);
	for (ll i = 1; i <= n; i++) 
		sm[i] = sm[i-1] + mn[i];

	ll ans = 0;
	for(ll i = 1; i <= n; ++i) {
		ll curr_left = a[i] + i, curr_min = a[i] + min(i, n+1-i);
		if(curr_left > c) continue;


		ll k = upper_bound(sm+1, sm+n+1, c - curr_left) - sm - 1;

		if(curr_min > mn[k])
			ans = max(ans, k + 1);
		else
			k = upper_bound(sm+1, sm+n+1, c - curr_left + curr_min) - sm - 1,
			ans = max(ans, k);
			
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

