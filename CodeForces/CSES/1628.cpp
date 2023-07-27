#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	ll n,x; cin >> n >> x;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	auto subset_sum = [&](int l, int r) {
		int n = r-l+1;
		vector<ll> res;

		for(int m = 0; m < (1 << n); ++m) {
			ll sm = 0;
			for(int j = 0; j < n; ++j)
				if(m & (1 << j)) sm += a[l+j];
			res.push_back(sm);
		}
		return res;
	};

	vector<ll> left = subset_sum(0, n/2-1);
	vector<ll> right = subset_sum(n/2, n-1);

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	ll ans = 0;
	for(auto i : left) {
		auto low = lower_bound(right.begin(), right.end(), x-i),
			 high = upper_bound(right.begin(), right.end(), x-i);
		ans += high-low;
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

