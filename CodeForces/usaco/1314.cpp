#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n, ans = 0; cin >> n;
	vector<ll> a(n+1), prefix(n+1, 0);

	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	vector<ll> b = a;
	sort(b.begin(), b.end());
	b[0] = -1;

	for(ll i = 1; i <= n; ++i) ans += i * b[i], prefix[i] = prefix[i-1] + b[i];

	ll q; cin >> q;
	while(q--) {
		ll i, j; cin >> i >> j;
		ll new_sum = ans;

		int old_index = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		// put in left of lower_bound
		int new_index = lower_bound(b.begin(), b.end(), j) - b.begin();
		new_sum += j * new_index - a[i] * old_index;

		if(new_index > old_index) {
			new_sum -= j;
			new_sum -= prefix[new_index - 1] - prefix[old_index];
		} else if(new_index < old_index) {
			new_sum += prefix[old_index - 1] - prefix[new_index - 1];
		}

		cout << new_sum << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

