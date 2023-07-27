#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using graph = vector<vector<int>>;
using ordered_set =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
	int n;
	cin >> n;
	ordered_set l,r;
	vector<int> a(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		r.insert(a[i]);
	}

	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		ll right = r.order_of_key(a[i]);
		ll left = i - l.order_of_key(a[i]);
		ans += left * right;

		l.insert(a[i]);
		r.erase(a[i]);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

